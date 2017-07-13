#pragma once

#include <string>
#include <iostream>

#include "ILWriterBase.h";

class Interceptor
{
protected:
	ICorProfilerInfo *corProfilerInfo;

public:
	Interceptor(ICorProfilerInfo *corProfilerInfo);
	bool IsMatch(const WCHAR *className, const WCHAR *methodName);
	void* GetInterceptILCode(FunctionInfo *functionInfo);
protected:
	virtual WCHAR *GetClassName2() = 0;
	virtual WCHAR *GetMethodName() = 0;
	virtual void GetInterceptorBeforeILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize) = 0;
	virtual void GetInterceptorAfterILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize) = 0;
	bool IsTiny(LPCBYTE methodBytes);
	mdModuleRef GetAssemblyToken(IMetaDataEmit *metaDataEmit, WCHAR *assemblyName);
	mdFieldDef GetFieldToken(FunctionInfo *functionInfo, WCHAR *fieldName);
	std::wstring GetModuleVID(FunctionInfo *functionInfo);
	void GetGeneralInterceptBeforeIL(IMetaDataEmit *metaDataEmit, const WCHAR *className, const WCHAR *methodName, BYTE *ilCode, int *ilCodeSize);
	void GetGeneralInterceptAfterIL(IMetaDataEmit *metaDataEmit, const WCHAR *className, const WCHAR *methodName, BYTE *ilCode, int *ilCodeSize);
};

class CallHandlerExecutionStep_Execute : Interceptor
{
public:
	CallHandlerExecutionStep_Execute(ICorProfilerInfo *corProfilerInfo);
protected:
	virtual WCHAR *GetClassName2();
	virtual WCHAR *GetMethodName();
	virtual void GetInterceptorBeforeILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize);
	virtual void GetInterceptorAfterILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize);
};

class HttpWebRequest_GetResponse : Interceptor
{
public:
	HttpWebRequest_GetResponse(ICorProfilerInfo *corProfilerInfo);
protected:
	virtual WCHAR *GetClassName2();
	virtual WCHAR *GetMethodName();
	virtual void GetInterceptorBeforeILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize);
	virtual void GetInterceptorAfterILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize);
};

class SqlCommand_ExecuteNonQuery : Interceptor
{
public:
	SqlCommand_ExecuteNonQuery(ICorProfilerInfo *corProfilerInfo);
protected:
	virtual WCHAR *GetClassName2();
	virtual WCHAR *GetMethodName();
	virtual void GetInterceptorBeforeILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize);
	virtual void GetInterceptorAfterILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize);
};

class SqlCommand_ExecuteReader : Interceptor
{
public:
	SqlCommand_ExecuteReader(ICorProfilerInfo *corProfilerInfo);
protected:
	virtual WCHAR *GetClassName2();
	virtual WCHAR *GetMethodName();
	virtual void GetInterceptorBeforeILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize);
	virtual void GetInterceptorAfterILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize);
};

class SqlCommand_ExecuteScalar : Interceptor
{
public:
	SqlCommand_ExecuteScalar(ICorProfilerInfo *corProfilerInfo);
protected:
	virtual WCHAR *GetClassName2();
	virtual WCHAR *GetMethodName();
	virtual void GetInterceptorBeforeILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize);
	virtual void GetInterceptorAfterILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize);
};

class RedisNativeClient_SendReceive : Interceptor
{
public:
	RedisNativeClient_SendReceive(ICorProfilerInfo *corProfilerInfo);
protected:
	virtual WCHAR *GetClassName2();
	virtual WCHAR *GetMethodName();
	virtual void GetInterceptorBeforeILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize);
	virtual void GetInterceptorAfterILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize);
};

class MySqlCommand_ExecuteReader : Interceptor
{
public:
	MySqlCommand_ExecuteReader(ICorProfilerInfo *corProfilerInfo);
protected:
	virtual WCHAR *GetClassName2();
	virtual WCHAR *GetMethodName();
	virtual void GetInterceptorBeforeILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize);
	virtual void GetInterceptorAfterILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize);
};

class ModelBase_ModelSend : Interceptor
{
public:
	ModelBase_ModelSend(ICorProfilerInfo *corProfilerInfo);
protected:
	virtual WCHAR *GetClassName2();
	virtual WCHAR *GetMethodName();
	virtual void GetInterceptorBeforeILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize);
	virtual void GetInterceptorAfterILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize);
};

class FastDFSClient_DownloadFile : Interceptor
{
public:
	FastDFSClient_DownloadFile(ICorProfilerInfo *corProfilerInfo);
protected:
	virtual WCHAR *GetClassName2();
	virtual WCHAR *GetMethodName();
	virtual void GetInterceptorBeforeILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize);
	virtual void GetInterceptorAfterILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize);
};

class FastDFSClient_UploadFile : Interceptor
{
public:
	FastDFSClient_UploadFile(ICorProfilerInfo *corProfilerInfo);
protected:
	virtual WCHAR *GetClassName2();
	virtual WCHAR *GetMethodName();
	virtual void GetInterceptorBeforeILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize);
	virtual void GetInterceptorAfterILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize);
};

class GeneralIntercept : Interceptor
{
public:
	GeneralIntercept(ICorProfilerInfo *corProfilerInfo);
protected:
	virtual WCHAR *GetClassName2();
	virtual WCHAR *GetMethodName();
	virtual void GetInterceptorBeforeILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize);
	virtual void GetInterceptorAfterILCode(IMetaDataEmit *metaDataEmit, FunctionInfo *functionInfo, BYTE *ilCode, int *ilCodeSize);
};

