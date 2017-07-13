#include "Interceptor.h";

#define Check(hr) if (FAILED(hr)) exit(1);

typedef struct {
	BYTE ldstr1;
	BYTE stringToken1[4];
	BYTE ldstr2;
	BYTE stringToken2[4];
	BYTE ldOp;
	BYTE call;
	BYTE callToken[4];
} BeforeIL;

SqlCommand_ExecuteNonQuery::SqlCommand_ExecuteNonQuery(ICorProfilerInfo *corProfilerInfo)
	:Interceptor(corProfilerInfo)
{

}

WCHAR *SqlCommand_ExecuteNonQuery::GetClassName2()
{
	return L"System.Data.SqlClient.SqlCommand";
}

WCHAR *SqlCommand_ExecuteNonQuery::GetMethodName()
{
	return L"ExecuteNonQuery";
}

void SqlCommand_ExecuteNonQuery::GetInterceptorBeforeILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize)
{
	mdTypeRef classToken;
	Check(metaDataEmit->DefineTypeRefByName(GetAssemblyToken(metaDataEmit, L"Pinpoint.Agent"), L"Pinpoint.Profiler.Bootstrap", &classToken));

	//calling convention, argument count, return type, arg type
	const BYTE signature[] = { IMAGE_CEE_CS_CALLCONV_DEFAULT, 3, ELEMENT_TYPE_VOID,
		ELEMENT_TYPE_STRING, ELEMENT_TYPE_STRING, ELEMENT_TYPE_OBJECT };

	mdMemberRef methodToken;
	Check(metaDataEmit->DefineMemberRef(classToken, L"InterceptMethodBegin", signature, sizeof(signature), &methodToken));

	BeforeIL beforeIL;
	mdString textToken;

	Check(metaDataEmit->DefineUserString(L"System.Data.SqlClient.SqlCommand", wcslen(L"System.Data.SqlClient.SqlCommand"), &textToken));
	beforeIL.ldstr1 = 0x72;
	memcpy(beforeIL.stringToken1, (void*)&textToken, sizeof(textToken));

	Check(metaDataEmit->DefineUserString(L"ExecuteNonQuery", wcslen(L"ExecuteNonQuery"), &textToken));
	beforeIL.ldstr2 = 0x72;
	memcpy(beforeIL.stringToken2, (void*)&textToken, sizeof(textToken));

	beforeIL.ldOp = 0x02;

	beforeIL.call = 0x28;
	memcpy(beforeIL.callToken, (void*)&methodToken, sizeof(methodToken));

	*ilCodeSize = sizeof(beforeIL);
	memcpy(ilCode, &beforeIL, *ilCodeSize);
}

void SqlCommand_ExecuteNonQuery::GetInterceptorAfterILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize)
{
	GetGeneralInterceptAfterIL(metaDataEmit, functionInfo->GetClassNameW(), functionInfo->GetFunctionName(), ilCode, ilCodeSize);
}