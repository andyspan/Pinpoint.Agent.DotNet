#include "Interceptor.h";

#define Check(hr) if (FAILED(hr)) exit(1);

GeneralIntercept::GeneralIntercept(ICorProfilerInfo *corProfilerInfo)
	:Interceptor(corProfilerInfo)
{

}

WCHAR *GeneralIntercept::GetClassName2()
{
	return L"";
}

WCHAR *GeneralIntercept::GetMethodName()
{
	return L"";
}

void GeneralIntercept::GetInterceptorBeforeILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize)
{
	GetGeneralInterceptBeforeIL(metaDataEmit, functionInfo->GetClassNameW(), functionInfo->GetFunctionName(), ilCode, ilCodeSize);
}

void GeneralIntercept::GetInterceptorAfterILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize)
{
	GetGeneralInterceptAfterIL(metaDataEmit, functionInfo->GetClassNameW(), functionInfo->GetFunctionName(), ilCode, ilCodeSize);
}