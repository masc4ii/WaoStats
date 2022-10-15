/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesRoutes.h"
#include "dropbox/endpoint/Endpoint.h"
using namespace dropboxQt;
using namespace files;

std::unique_ptr<Metadata> FilesRoutes::alphaGetMetadata(const AlphaGetMetadataArg& arg ){
    return alphaGetMetadata_Async(arg)->waitForResultAndRelease();
}

DropboxTask<Metadata>* FilesRoutes::alphaGetMetadata_Async(const AlphaGetMetadataArg& arg)
{
    DropboxTask<Metadata>* t = m_end_point->produceTask<Metadata>();
    m_end_point->rpcStyle<
        AlphaGetMetadataArg,
        Metadata,
        Metadata::factory,
        AlphaGetMetadataErrorException>
        ("2/files/alpha/get_metadata",
        arg,
        t);
    return t;
}

void FilesRoutes::alphaGetMetadata_AsyncCB(
    const AlphaGetMetadataArg& arg,
    std::function<void(std::unique_ptr<Metadata>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        AlphaGetMetadataArg,
        Metadata,
        Metadata::factory,
        AlphaGetMetadataErrorException>
        ("2/files/alpha/get_metadata",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<FileMetadata> FilesRoutes::alphaUpload(const CommitInfoWithProperties& arg , QIODevice* data){
    return alphaUpload_Async(arg, data)->waitForResultAndRelease();
}

DropboxTask<FileMetadata>* FilesRoutes::alphaUpload_Async(const CommitInfoWithProperties& arg, QIODevice* data)
{
    DropboxTask<FileMetadata>* t = m_end_point->produceTask<FileMetadata>();
    m_end_point->uploadStyle<
        CommitInfoWithProperties,
        FileMetadata,
        FileMetadata::factory,
        UploadErrorWithPropertiesException>
        ("2/files/alpha/upload",
        arg,
        data,
        t);
    return t;
}

void FilesRoutes::alphaUpload_AsyncCB(
    const CommitInfoWithProperties& arg,
    QIODevice* data,
    std::function<void(std::unique_ptr<FileMetadata>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->uploadStyle<
        CommitInfoWithProperties,
        FileMetadata,
        FileMetadata::factory,
        UploadErrorWithPropertiesException>
        ("2/files/alpha/upload",
        arg,
        data,
        completed_callback,
        failed_callback);
}

std::unique_ptr<Metadata> FilesRoutes::copy(const RelocationArg& arg ){
    return copy_Async(arg)->waitForResultAndRelease();
}

DropboxTask<Metadata>* FilesRoutes::copy_Async(const RelocationArg& arg)
{
    DropboxTask<Metadata>* t = m_end_point->produceTask<Metadata>();
    m_end_point->rpcStyle<
        RelocationArg,
        Metadata,
        Metadata::factory,
        RelocationErrorException>
        ("2/files/copy",
        arg,
        t);
    return t;
}

void FilesRoutes::copy_AsyncCB(
    const RelocationArg& arg,
    std::function<void(std::unique_ptr<Metadata>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        RelocationArg,
        Metadata,
        Metadata::factory,
        RelocationErrorException>
        ("2/files/copy",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<GetCopyReferenceResult> FilesRoutes::copyReferenceGet(const GetCopyReferenceArg& arg ){
    return copyReferenceGet_Async(arg)->waitForResultAndRelease();
}

DropboxTask<GetCopyReferenceResult>* FilesRoutes::copyReferenceGet_Async(const GetCopyReferenceArg& arg)
{
    DropboxTask<GetCopyReferenceResult>* t = m_end_point->produceTask<GetCopyReferenceResult>();
    m_end_point->rpcStyle<
        GetCopyReferenceArg,
        GetCopyReferenceResult,
        GetCopyReferenceResult::factory,
        GetCopyReferenceErrorException>
        ("2/files/copy_reference/get",
        arg,
        t);
    return t;
}

void FilesRoutes::copyReferenceGet_AsyncCB(
    const GetCopyReferenceArg& arg,
    std::function<void(std::unique_ptr<GetCopyReferenceResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        GetCopyReferenceArg,
        GetCopyReferenceResult,
        GetCopyReferenceResult::factory,
        GetCopyReferenceErrorException>
        ("2/files/copy_reference/get",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<SaveCopyReferenceResult> FilesRoutes::copyReferenceSave(const SaveCopyReferenceArg& arg ){
    return copyReferenceSave_Async(arg)->waitForResultAndRelease();
}

DropboxTask<SaveCopyReferenceResult>* FilesRoutes::copyReferenceSave_Async(const SaveCopyReferenceArg& arg)
{
    DropboxTask<SaveCopyReferenceResult>* t = m_end_point->produceTask<SaveCopyReferenceResult>();
    m_end_point->rpcStyle<
        SaveCopyReferenceArg,
        SaveCopyReferenceResult,
        SaveCopyReferenceResult::factory,
        SaveCopyReferenceErrorException>
        ("2/files/copy_reference/save",
        arg,
        t);
    return t;
}

void FilesRoutes::copyReferenceSave_AsyncCB(
    const SaveCopyReferenceArg& arg,
    std::function<void(std::unique_ptr<SaveCopyReferenceResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        SaveCopyReferenceArg,
        SaveCopyReferenceResult,
        SaveCopyReferenceResult::factory,
        SaveCopyReferenceErrorException>
        ("2/files/copy_reference/save",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<FolderMetadata> FilesRoutes::createFolder(const CreateFolderArg& arg ){
    return createFolder_Async(arg)->waitForResultAndRelease();
}

DropboxTask<FolderMetadata>* FilesRoutes::createFolder_Async(const CreateFolderArg& arg)
{
    DropboxTask<FolderMetadata>* t = m_end_point->produceTask<FolderMetadata>();
    m_end_point->rpcStyle<
        CreateFolderArg,
        FolderMetadata,
        FolderMetadata::factory,
        CreateFolderErrorException>
        ("2/files/create_folder",
        arg,
        t);
    return t;
}

void FilesRoutes::createFolder_AsyncCB(
    const CreateFolderArg& arg,
    std::function<void(std::unique_ptr<FolderMetadata>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        CreateFolderArg,
        FolderMetadata,
        FolderMetadata::factory,
        CreateFolderErrorException>
        ("2/files/create_folder",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<Metadata> FilesRoutes::deleteOperation(const DeleteArg& arg ){
    return deleteOperation_Async(arg)->waitForResultAndRelease();
}

DropboxTask<Metadata>* FilesRoutes::deleteOperation_Async(const DeleteArg& arg)
{
    DropboxTask<Metadata>* t = m_end_point->produceTask<Metadata>();
    m_end_point->rpcStyle<
        DeleteArg,
        Metadata,
        Metadata::factory,
        DeleteErrorException>
        ("2/files/delete",
        arg,
        t);
    return t;
}

void FilesRoutes::deleteOperation_AsyncCB(
    const DeleteArg& arg,
    std::function<void(std::unique_ptr<Metadata>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        DeleteArg,
        Metadata,
        Metadata::factory,
        DeleteErrorException>
        ("2/files/delete",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<FileMetadata> FilesRoutes::download(const DownloadArg& arg , QIODevice* data){
    return download_Async(arg, data)->waitForResultAndRelease();
}

DropboxTask<FileMetadata>* FilesRoutes::download_Async(const DownloadArg& arg, QIODevice* data)
{
    DropboxTask<FileMetadata>* t = m_end_point->produceTask<FileMetadata>();
    m_end_point->downloadStyle<
        DownloadArg,
        FileMetadata,
        FileMetadata::factory,
        DownloadErrorException>
        ("2/files/download",
        arg,
        data,
        t);
    return t;
}

void FilesRoutes::download_AsyncCB(
    const DownloadArg& arg,
    QIODevice* data,
    std::function<void(std::unique_ptr<FileMetadata>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->downloadStyle<
        DownloadArg,
        FileMetadata,
        FileMetadata::factory,
        DownloadErrorException>
        ("2/files/download",
        arg,
        data,
        completed_callback,
        failed_callback);
}

std::unique_ptr<Metadata> FilesRoutes::getMetadata(const GetMetadataArg& arg ){
    return getMetadata_Async(arg)->waitForResultAndRelease();
}

DropboxTask<Metadata>* FilesRoutes::getMetadata_Async(const GetMetadataArg& arg)
{
    DropboxTask<Metadata>* t = m_end_point->produceTask<Metadata>();
    m_end_point->rpcStyle<
        GetMetadataArg,
        Metadata,
        Metadata::factory,
        GetMetadataErrorException>
        ("2/files/get_metadata",
        arg,
        t);
    return t;
}

void FilesRoutes::getMetadata_AsyncCB(
    const GetMetadataArg& arg,
    std::function<void(std::unique_ptr<Metadata>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        GetMetadataArg,
        Metadata,
        Metadata::factory,
        GetMetadataErrorException>
        ("2/files/get_metadata",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<FileMetadata> FilesRoutes::getPreview(const PreviewArg& arg , QIODevice* data){
    return getPreview_Async(arg, data)->waitForResultAndRelease();
}

DropboxTask<FileMetadata>* FilesRoutes::getPreview_Async(const PreviewArg& arg, QIODevice* data)
{
    DropboxTask<FileMetadata>* t = m_end_point->produceTask<FileMetadata>();
    m_end_point->downloadStyle<
        PreviewArg,
        FileMetadata,
        FileMetadata::factory,
        PreviewErrorException>
        ("2/files/get_preview",
        arg,
        data,
        t);
    return t;
}

void FilesRoutes::getPreview_AsyncCB(
    const PreviewArg& arg,
    QIODevice* data,
    std::function<void(std::unique_ptr<FileMetadata>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->downloadStyle<
        PreviewArg,
        FileMetadata,
        FileMetadata::factory,
        PreviewErrorException>
        ("2/files/get_preview",
        arg,
        data,
        completed_callback,
        failed_callback);
}

std::unique_ptr<GetTemporaryLinkResult> FilesRoutes::getTemporaryLink(const GetTemporaryLinkArg& arg ){
    return getTemporaryLink_Async(arg)->waitForResultAndRelease();
}

DropboxTask<GetTemporaryLinkResult>* FilesRoutes::getTemporaryLink_Async(const GetTemporaryLinkArg& arg)
{
    DropboxTask<GetTemporaryLinkResult>* t = m_end_point->produceTask<GetTemporaryLinkResult>();
    m_end_point->rpcStyle<
        GetTemporaryLinkArg,
        GetTemporaryLinkResult,
        GetTemporaryLinkResult::factory,
        GetTemporaryLinkErrorException>
        ("2/files/get_temporary_link",
        arg,
        t);
    return t;
}

void FilesRoutes::getTemporaryLink_AsyncCB(
    const GetTemporaryLinkArg& arg,
    std::function<void(std::unique_ptr<GetTemporaryLinkResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        GetTemporaryLinkArg,
        GetTemporaryLinkResult,
        GetTemporaryLinkResult::factory,
        GetTemporaryLinkErrorException>
        ("2/files/get_temporary_link",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<FileMetadata> FilesRoutes::getThumbnail(const ThumbnailArg& arg , QIODevice* data){
    return getThumbnail_Async(arg, data)->waitForResultAndRelease();
}

DropboxTask<FileMetadata>* FilesRoutes::getThumbnail_Async(const ThumbnailArg& arg, QIODevice* data)
{
    DropboxTask<FileMetadata>* t = m_end_point->produceTask<FileMetadata>();
    m_end_point->downloadStyle<
        ThumbnailArg,
        FileMetadata,
        FileMetadata::factory,
        ThumbnailErrorException>
        ("2/files/get_thumbnail",
        arg,
        data,
        t);
    return t;
}

void FilesRoutes::getThumbnail_AsyncCB(
    const ThumbnailArg& arg,
    QIODevice* data,
    std::function<void(std::unique_ptr<FileMetadata>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->downloadStyle<
        ThumbnailArg,
        FileMetadata,
        FileMetadata::factory,
        ThumbnailErrorException>
        ("2/files/get_thumbnail",
        arg,
        data,
        completed_callback,
        failed_callback);
}

std::unique_ptr<ListFolderResult> FilesRoutes::listFolder(const ListFolderArg& arg ){
    return listFolder_Async(arg)->waitForResultAndRelease();
}

DropboxTask<ListFolderResult>* FilesRoutes::listFolder_Async(const ListFolderArg& arg)
{
    DropboxTask<ListFolderResult>* t = m_end_point->produceTask<ListFolderResult>();
    m_end_point->rpcStyle<
        ListFolderArg,
        ListFolderResult,
        ListFolderResult::factory,
        ListFolderErrorException>
        ("2/files/list_folder",
        arg,
        t);
    return t;
}

void FilesRoutes::listFolder_AsyncCB(
    const ListFolderArg& arg,
    std::function<void(std::unique_ptr<ListFolderResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        ListFolderArg,
        ListFolderResult,
        ListFolderResult::factory,
        ListFolderErrorException>
        ("2/files/list_folder",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<ListFolderResult> FilesRoutes::listFolderContinue(const ListFolderContinueArg& arg ){
    return listFolderContinue_Async(arg)->waitForResultAndRelease();
}

DropboxTask<ListFolderResult>* FilesRoutes::listFolderContinue_Async(const ListFolderContinueArg& arg)
{
    DropboxTask<ListFolderResult>* t = m_end_point->produceTask<ListFolderResult>();
    m_end_point->rpcStyle<
        ListFolderContinueArg,
        ListFolderResult,
        ListFolderResult::factory,
        ListFolderContinueErrorException>
        ("2/files/list_folder/continue",
        arg,
        t);
    return t;
}

void FilesRoutes::listFolderContinue_AsyncCB(
    const ListFolderContinueArg& arg,
    std::function<void(std::unique_ptr<ListFolderResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        ListFolderContinueArg,
        ListFolderResult,
        ListFolderResult::factory,
        ListFolderContinueErrorException>
        ("2/files/list_folder/continue",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<ListFolderGetLatestCursorResult> FilesRoutes::listFolderGetLatestCursor(const ListFolderArg& arg ){
    return listFolderGetLatestCursor_Async(arg)->waitForResultAndRelease();
}

DropboxTask<ListFolderGetLatestCursorResult>* FilesRoutes::listFolderGetLatestCursor_Async(const ListFolderArg& arg)
{
    DropboxTask<ListFolderGetLatestCursorResult>* t = m_end_point->produceTask<ListFolderGetLatestCursorResult>();
    m_end_point->rpcStyle<
        ListFolderArg,
        ListFolderGetLatestCursorResult,
        ListFolderGetLatestCursorResult::factory,
        ListFolderErrorException>
        ("2/files/list_folder/get_latest_cursor",
        arg,
        t);
    return t;
}

void FilesRoutes::listFolderGetLatestCursor_AsyncCB(
    const ListFolderArg& arg,
    std::function<void(std::unique_ptr<ListFolderGetLatestCursorResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        ListFolderArg,
        ListFolderGetLatestCursorResult,
        ListFolderGetLatestCursorResult::factory,
        ListFolderErrorException>
        ("2/files/list_folder/get_latest_cursor",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<ListFolderLongpollResult> FilesRoutes::listFolderLongpoll(const ListFolderLongpollArg& arg ){
    return listFolderLongpoll_Async(arg)->waitForResultAndRelease();
}

DropboxTask<ListFolderLongpollResult>* FilesRoutes::listFolderLongpoll_Async(const ListFolderLongpollArg& arg)
{
    DropboxTask<ListFolderLongpollResult>* t = m_end_point->produceTask<ListFolderLongpollResult>();
    m_end_point->rpcStyle<
        ListFolderLongpollArg,
        ListFolderLongpollResult,
        ListFolderLongpollResult::factory,
        ListFolderLongpollErrorException>
        ("2/files/list_folder/longpoll",
        arg,
        t);
    return t;
}

void FilesRoutes::listFolderLongpoll_AsyncCB(
    const ListFolderLongpollArg& arg,
    std::function<void(std::unique_ptr<ListFolderLongpollResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        ListFolderLongpollArg,
        ListFolderLongpollResult,
        ListFolderLongpollResult::factory,
        ListFolderLongpollErrorException>
        ("2/files/list_folder/longpoll",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<ListRevisionsResult> FilesRoutes::listRevisions(const ListRevisionsArg& arg ){
    return listRevisions_Async(arg)->waitForResultAndRelease();
}

DropboxTask<ListRevisionsResult>* FilesRoutes::listRevisions_Async(const ListRevisionsArg& arg)
{
    DropboxTask<ListRevisionsResult>* t = m_end_point->produceTask<ListRevisionsResult>();
    m_end_point->rpcStyle<
        ListRevisionsArg,
        ListRevisionsResult,
        ListRevisionsResult::factory,
        ListRevisionsErrorException>
        ("2/files/list_revisions",
        arg,
        t);
    return t;
}

void FilesRoutes::listRevisions_AsyncCB(
    const ListRevisionsArg& arg,
    std::function<void(std::unique_ptr<ListRevisionsResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        ListRevisionsArg,
        ListRevisionsResult,
        ListRevisionsResult::factory,
        ListRevisionsErrorException>
        ("2/files/list_revisions",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<Metadata> FilesRoutes::move(const RelocationArg& arg ){
    return move_Async(arg)->waitForResultAndRelease();
}

DropboxTask<Metadata>* FilesRoutes::move_Async(const RelocationArg& arg)
{
    DropboxTask<Metadata>* t = m_end_point->produceTask<Metadata>();
    m_end_point->rpcStyle<
        RelocationArg,
        Metadata,
        Metadata::factory,
        RelocationErrorException>
        ("2/files/move",
        arg,
        t);
    return t;
}

void FilesRoutes::move_AsyncCB(
    const RelocationArg& arg,
    std::function<void(std::unique_ptr<Metadata>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        RelocationArg,
        Metadata,
        Metadata::factory,
        RelocationErrorException>
        ("2/files/move",
        arg,
        completed_callback,
        failed_callback);
}

void FilesRoutes::permanentlyDelete(const DeleteArg& arg ){
    permanentlyDelete_Async(arg)->waitForResultAndRelease();
}

DropboxVoidTask* FilesRoutes::permanentlyDelete_Async(const DeleteArg& arg)
{
    DropboxVoidTask* t = m_end_point->produceVoidTask();
    m_end_point->rpcStyle<
        DeleteArg,
        DeleteErrorException>
        ("2/files/permanently_delete",
        arg,
        t);
    return t;
}

void FilesRoutes::permanentlyDelete_AsyncCB(
    const DeleteArg& arg,
    std::function<void()> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        DeleteArg,
        DeleteErrorException>
        ("2/files/permanently_delete",
        arg,
        completed_callback,
        failed_callback);
}

void FilesRoutes::propertiesAdd(const PropertyGroupWithPath& arg ){
    propertiesAdd_Async(arg)->waitForResultAndRelease();
}

DropboxVoidTask* FilesRoutes::propertiesAdd_Async(const PropertyGroupWithPath& arg)
{
    DropboxVoidTask* t = m_end_point->produceVoidTask();
    m_end_point->rpcStyle<
        PropertyGroupWithPath,
        AddPropertiesErrorException>
        ("2/files/properties/add",
        arg,
        t);
    return t;
}

void FilesRoutes::propertiesAdd_AsyncCB(
    const PropertyGroupWithPath& arg,
    std::function<void()> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        PropertyGroupWithPath,
        AddPropertiesErrorException>
        ("2/files/properties/add",
        arg,
        completed_callback,
        failed_callback);
}

void FilesRoutes::propertiesOverwrite(const PropertyGroupWithPath& arg ){
    propertiesOverwrite_Async(arg)->waitForResultAndRelease();
}

DropboxVoidTask* FilesRoutes::propertiesOverwrite_Async(const PropertyGroupWithPath& arg)
{
    DropboxVoidTask* t = m_end_point->produceVoidTask();
    m_end_point->rpcStyle<
        PropertyGroupWithPath,
        InvalidPropertyGroupErrorException>
        ("2/files/properties/overwrite",
        arg,
        t);
    return t;
}

void FilesRoutes::propertiesOverwrite_AsyncCB(
    const PropertyGroupWithPath& arg,
    std::function<void()> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        PropertyGroupWithPath,
        InvalidPropertyGroupErrorException>
        ("2/files/properties/overwrite",
        arg,
        completed_callback,
        failed_callback);
}

void FilesRoutes::propertiesRemove(const RemovePropertiesArg& arg ){
    propertiesRemove_Async(arg)->waitForResultAndRelease();
}

DropboxVoidTask* FilesRoutes::propertiesRemove_Async(const RemovePropertiesArg& arg)
{
    DropboxVoidTask* t = m_end_point->produceVoidTask();
    m_end_point->rpcStyle<
        RemovePropertiesArg,
        RemovePropertiesErrorException>
        ("2/files/properties/remove",
        arg,
        t);
    return t;
}

void FilesRoutes::propertiesRemove_AsyncCB(
    const RemovePropertiesArg& arg,
    std::function<void()> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        RemovePropertiesArg,
        RemovePropertiesErrorException>
        ("2/files/properties/remove",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<properties::GetPropertyTemplateResult> FilesRoutes::propertiesTemplateGet(const properties::GetPropertyTemplateArg& arg ){
    return propertiesTemplateGet_Async(arg)->waitForResultAndRelease();
}

DropboxTask<properties::GetPropertyTemplateResult>* FilesRoutes::propertiesTemplateGet_Async(const properties::GetPropertyTemplateArg& arg)
{
    DropboxTask<properties::GetPropertyTemplateResult>* t = m_end_point->produceTask<properties::GetPropertyTemplateResult>();
    m_end_point->rpcStyle<
        properties::GetPropertyTemplateArg,
        properties::GetPropertyTemplateResult,
        properties::GetPropertyTemplateResult::factory,
        PropertyTemplateErrorException>
        ("2/files/properties/template/get",
        arg,
        t);
    return t;
}

void FilesRoutes::propertiesTemplateGet_AsyncCB(
    const properties::GetPropertyTemplateArg& arg,
    std::function<void(std::unique_ptr<properties::GetPropertyTemplateResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        properties::GetPropertyTemplateArg,
        properties::GetPropertyTemplateResult,
        properties::GetPropertyTemplateResult::factory,
        PropertyTemplateErrorException>
        ("2/files/properties/template/get",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<properties::ListPropertyTemplateIds> FilesRoutes::propertiesTemplateList(void){
    return propertiesTemplateList_Async()->waitForResultAndRelease();
}

DropboxTask<properties::ListPropertyTemplateIds>* FilesRoutes::propertiesTemplateList_Async()
{
    DropboxTask<properties::ListPropertyTemplateIds>* t = m_end_point->produceTask<properties::ListPropertyTemplateIds>();
    m_end_point->rpcStyle<
        properties::ListPropertyTemplateIds,
        properties::ListPropertyTemplateIds::factory,
        PropertyTemplateErrorException>
        ("2/files/properties/template/list",
        t);
    return t;
}

void FilesRoutes::propertiesTemplateList_AsyncCB(
    std::function<void(std::unique_ptr<properties::ListPropertyTemplateIds>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        properties::ListPropertyTemplateIds,
        properties::ListPropertyTemplateIds::factory,
        PropertyTemplateErrorException>
        ("2/files/properties/template/list",
        completed_callback,
        failed_callback);
}

void FilesRoutes::propertiesUpdate(const UpdatePropertyGroupArg& arg ){
    propertiesUpdate_Async(arg)->waitForResultAndRelease();
}

DropboxVoidTask* FilesRoutes::propertiesUpdate_Async(const UpdatePropertyGroupArg& arg)
{
    DropboxVoidTask* t = m_end_point->produceVoidTask();
    m_end_point->rpcStyle<
        UpdatePropertyGroupArg,
        UpdatePropertiesErrorException>
        ("2/files/properties/update",
        arg,
        t);
    return t;
}

void FilesRoutes::propertiesUpdate_AsyncCB(
    const UpdatePropertyGroupArg& arg,
    std::function<void()> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        UpdatePropertyGroupArg,
        UpdatePropertiesErrorException>
        ("2/files/properties/update",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<FileMetadata> FilesRoutes::restore(const RestoreArg& arg ){
    return restore_Async(arg)->waitForResultAndRelease();
}

DropboxTask<FileMetadata>* FilesRoutes::restore_Async(const RestoreArg& arg)
{
    DropboxTask<FileMetadata>* t = m_end_point->produceTask<FileMetadata>();
    m_end_point->rpcStyle<
        RestoreArg,
        FileMetadata,
        FileMetadata::factory,
        RestoreErrorException>
        ("2/files/restore",
        arg,
        t);
    return t;
}

void FilesRoutes::restore_AsyncCB(
    const RestoreArg& arg,
    std::function<void(std::unique_ptr<FileMetadata>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        RestoreArg,
        FileMetadata,
        FileMetadata::factory,
        RestoreErrorException>
        ("2/files/restore",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<SaveUrlResult> FilesRoutes::saveUrl(const SaveUrlArg& arg ){
    return saveUrl_Async(arg)->waitForResultAndRelease();
}

DropboxTask<SaveUrlResult>* FilesRoutes::saveUrl_Async(const SaveUrlArg& arg)
{
    DropboxTask<SaveUrlResult>* t = m_end_point->produceTask<SaveUrlResult>();
    m_end_point->rpcStyle<
        SaveUrlArg,
        SaveUrlResult,
        SaveUrlResult::factory,
        SaveUrlErrorException>
        ("2/files/save_url",
        arg,
        t);
    return t;
}

void FilesRoutes::saveUrl_AsyncCB(
    const SaveUrlArg& arg,
    std::function<void(std::unique_ptr<SaveUrlResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        SaveUrlArg,
        SaveUrlResult,
        SaveUrlResult::factory,
        SaveUrlErrorException>
        ("2/files/save_url",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<SaveUrlJobStatus> FilesRoutes::saveUrlCheckJobStatus(const async::PollArg& arg ){
    return saveUrlCheckJobStatus_Async(arg)->waitForResultAndRelease();
}

DropboxTask<SaveUrlJobStatus>* FilesRoutes::saveUrlCheckJobStatus_Async(const async::PollArg& arg)
{
    DropboxTask<SaveUrlJobStatus>* t = m_end_point->produceTask<SaveUrlJobStatus>();
    m_end_point->rpcStyle<
        async::PollArg,
        SaveUrlJobStatus,
        SaveUrlJobStatus::factory,
        PollErrorException>
        ("2/files/save_url/check_job_status",
        arg,
        t);
    return t;
}

void FilesRoutes::saveUrlCheckJobStatus_AsyncCB(
    const async::PollArg& arg,
    std::function<void(std::unique_ptr<SaveUrlJobStatus>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        async::PollArg,
        SaveUrlJobStatus,
        SaveUrlJobStatus::factory,
        PollErrorException>
        ("2/files/save_url/check_job_status",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<SearchResult> FilesRoutes::search(const SearchArg& arg ){
    return search_Async(arg)->waitForResultAndRelease();
}

DropboxTask<SearchResult>* FilesRoutes::search_Async(const SearchArg& arg)
{
    DropboxTask<SearchResult>* t = m_end_point->produceTask<SearchResult>();
    m_end_point->rpcStyle<
        SearchArg,
        SearchResult,
        SearchResult::factory,
        SearchErrorException>
        ("2/files/search",
        arg,
        t);
    return t;
}

void FilesRoutes::search_AsyncCB(
    const SearchArg& arg,
    std::function<void(std::unique_ptr<SearchResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        SearchArg,
        SearchResult,
        SearchResult::factory,
        SearchErrorException>
        ("2/files/search",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<FileMetadata> FilesRoutes::upload(const CommitInfo& arg , QIODevice* data){
    return upload_Async(arg, data)->waitForResultAndRelease();
}

DropboxTask<FileMetadata>* FilesRoutes::upload_Async(const CommitInfo& arg, QIODevice* data)
{
    DropboxTask<FileMetadata>* t = m_end_point->produceTask<FileMetadata>();
    m_end_point->uploadStyle<
        CommitInfo,
        FileMetadata,
        FileMetadata::factory,
        UploadErrorException>
        ("2/files/upload",
        arg,
        data,
        t);
    return t;
}

void FilesRoutes::upload_AsyncCB(
    const CommitInfo& arg,
    QIODevice* data,
    std::function<void(std::unique_ptr<FileMetadata>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->uploadStyle<
        CommitInfo,
        FileMetadata,
        FileMetadata::factory,
        UploadErrorException>
        ("2/files/upload",
        arg,
        data,
        completed_callback,
        failed_callback);
}

void FilesRoutes::uploadSessionAppend(const UploadSessionCursor& arg , QIODevice* data){
    uploadSessionAppend_Async(arg, data)->waitForResultAndRelease();
}

DropboxVoidTask* FilesRoutes::uploadSessionAppend_Async(const UploadSessionCursor& arg, QIODevice* data)
{
    DropboxVoidTask* t = m_end_point->produceVoidTask();
    m_end_point->uploadStyle<
        UploadSessionCursor,
        UploadSessionLookupErrorException>
        ("2/files/upload_session/append",
        arg,
        data,
        t);
    return t;
}

void FilesRoutes::uploadSessionAppend_AsyncCB(
    const UploadSessionCursor& arg,
    QIODevice* data,
    std::function<void()> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->uploadStyle<
        UploadSessionCursor,
        UploadSessionLookupErrorException>
        ("2/files/upload_session/append",
        arg,
        data,
        completed_callback,
        failed_callback);
}

void FilesRoutes::uploadSessionAppendV2(const UploadSessionAppendArg& arg , QIODevice* data){
    uploadSessionAppendV2_Async(arg, data)->waitForResultAndRelease();
}

DropboxVoidTask* FilesRoutes::uploadSessionAppendV2_Async(const UploadSessionAppendArg& arg, QIODevice* data)
{
    DropboxVoidTask* t = m_end_point->produceVoidTask();
    m_end_point->uploadStyle<
        UploadSessionAppendArg,
        UploadSessionLookupErrorException>
        ("2/files/upload_session/append_v2",
        arg,
        data,
        t);
    return t;
}

void FilesRoutes::uploadSessionAppendV2_AsyncCB(
    const UploadSessionAppendArg& arg,
    QIODevice* data,
    std::function<void()> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->uploadStyle<
        UploadSessionAppendArg,
        UploadSessionLookupErrorException>
        ("2/files/upload_session/append_v2",
        arg,
        data,
        completed_callback,
        failed_callback);
}

std::unique_ptr<FileMetadata> FilesRoutes::uploadSessionFinish(const UploadSessionFinishArg& arg , QIODevice* data){
    return uploadSessionFinish_Async(arg, data)->waitForResultAndRelease();
}

DropboxTask<FileMetadata>* FilesRoutes::uploadSessionFinish_Async(const UploadSessionFinishArg& arg, QIODevice* data)
{
    DropboxTask<FileMetadata>* t = m_end_point->produceTask<FileMetadata>();
    m_end_point->uploadStyle<
        UploadSessionFinishArg,
        FileMetadata,
        FileMetadata::factory,
        UploadSessionFinishErrorException>
        ("2/files/upload_session/finish",
        arg,
        data,
        t);
    return t;
}

void FilesRoutes::uploadSessionFinish_AsyncCB(
    const UploadSessionFinishArg& arg,
    QIODevice* data,
    std::function<void(std::unique_ptr<FileMetadata>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->uploadStyle<
        UploadSessionFinishArg,
        FileMetadata,
        FileMetadata::factory,
        UploadSessionFinishErrorException>
        ("2/files/upload_session/finish",
        arg,
        data,
        completed_callback,
        failed_callback);
}

std::unique_ptr<async::LaunchEmptyResult> FilesRoutes::uploadSessionFinishBatch(const UploadSessionFinishBatchArg& arg ){
    return uploadSessionFinishBatch_Async(arg)->waitForResultAndRelease();
}

DropboxTask<async::LaunchEmptyResult>* FilesRoutes::uploadSessionFinishBatch_Async(const UploadSessionFinishBatchArg& arg)
{
    DropboxTask<async::LaunchEmptyResult>* t = m_end_point->produceTask<async::LaunchEmptyResult>();
    m_end_point->rpcStyle<
        UploadSessionFinishBatchArg,
        async::LaunchEmptyResult,
        async::LaunchEmptyResult::factory,
        DropboxException>
        ("2/files/upload_session/finish_batch",
        arg,
        t);
    return t;
}

void FilesRoutes::uploadSessionFinishBatch_AsyncCB(
    const UploadSessionFinishBatchArg& arg,
    std::function<void(std::unique_ptr<async::LaunchEmptyResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        UploadSessionFinishBatchArg,
        async::LaunchEmptyResult,
        async::LaunchEmptyResult::factory,
        DropboxException>
        ("2/files/upload_session/finish_batch",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<UploadSessionFinishBatchJobStatus> FilesRoutes::uploadSessionFinishBatchCheck(const async::PollArg& arg ){
    return uploadSessionFinishBatchCheck_Async(arg)->waitForResultAndRelease();
}

DropboxTask<UploadSessionFinishBatchJobStatus>* FilesRoutes::uploadSessionFinishBatchCheck_Async(const async::PollArg& arg)
{
    DropboxTask<UploadSessionFinishBatchJobStatus>* t = m_end_point->produceTask<UploadSessionFinishBatchJobStatus>();
    m_end_point->rpcStyle<
        async::PollArg,
        UploadSessionFinishBatchJobStatus,
        UploadSessionFinishBatchJobStatus::factory,
        PollErrorException>
        ("2/files/upload_session/finish_batch/check",
        arg,
        t);
    return t;
}

void FilesRoutes::uploadSessionFinishBatchCheck_AsyncCB(
    const async::PollArg& arg,
    std::function<void(std::unique_ptr<UploadSessionFinishBatchJobStatus>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        async::PollArg,
        UploadSessionFinishBatchJobStatus,
        UploadSessionFinishBatchJobStatus::factory,
        PollErrorException>
        ("2/files/upload_session/finish_batch/check",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<UploadSessionStartResult> FilesRoutes::uploadSessionStart(const UploadSessionStartArg& arg , QIODevice* data){
    return uploadSessionStart_Async(arg, data)->waitForResultAndRelease();
}

DropboxTask<UploadSessionStartResult>* FilesRoutes::uploadSessionStart_Async(const UploadSessionStartArg& arg, QIODevice* data)
{
    DropboxTask<UploadSessionStartResult>* t = m_end_point->produceTask<UploadSessionStartResult>();
    m_end_point->uploadStyle<
        UploadSessionStartArg,
        UploadSessionStartResult,
        UploadSessionStartResult::factory,
        DropboxException>
        ("2/files/upload_session/start",
        arg,
        data,
        t);
    return t;
}

void FilesRoutes::uploadSessionStart_AsyncCB(
    const UploadSessionStartArg& arg,
    QIODevice* data,
    std::function<void(std::unique_ptr<UploadSessionStartResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->uploadStyle<
        UploadSessionStartArg,
        UploadSessionStartResult,
        UploadSessionStartResult::factory,
        DropboxException>
        ("2/files/upload_session/start",
        arg,
        data,
        completed_callback,
        failed_callback);
}

IMPLEMENT_API_ERR_EXCEPTION(AlphaGetMetadataErrorException, files::AlphaGetMetadataError);
IMPLEMENT_API_ERR_EXCEPTION(UploadErrorWithPropertiesException, files::UploadErrorWithProperties);
IMPLEMENT_API_ERR_EXCEPTION(RelocationErrorException, files::RelocationError);
IMPLEMENT_API_ERR_EXCEPTION(GetCopyReferenceErrorException, files::GetCopyReferenceError);
IMPLEMENT_API_ERR_EXCEPTION(SaveCopyReferenceErrorException, files::SaveCopyReferenceError);
IMPLEMENT_API_ERR_EXCEPTION(CreateFolderErrorException, files::CreateFolderError);
IMPLEMENT_API_ERR_EXCEPTION(DeleteErrorException, files::DeleteError);
IMPLEMENT_API_ERR_EXCEPTION(DownloadErrorException, files::DownloadError);
IMPLEMENT_API_ERR_EXCEPTION(GetMetadataErrorException, files::GetMetadataError);
IMPLEMENT_API_ERR_EXCEPTION(PreviewErrorException, files::PreviewError);
IMPLEMENT_API_ERR_EXCEPTION(GetTemporaryLinkErrorException, files::GetTemporaryLinkError);
IMPLEMENT_API_ERR_EXCEPTION(ThumbnailErrorException, files::ThumbnailError);
IMPLEMENT_API_ERR_EXCEPTION(ListFolderErrorException, files::ListFolderError);
IMPLEMENT_API_ERR_EXCEPTION(ListFolderContinueErrorException, files::ListFolderContinueError);
IMPLEMENT_API_ERR_EXCEPTION(ListFolderLongpollErrorException, files::ListFolderLongpollError);
IMPLEMENT_API_ERR_EXCEPTION(ListRevisionsErrorException, files::ListRevisionsError);
IMPLEMENT_API_ERR_EXCEPTION(AddPropertiesErrorException, files::AddPropertiesError);
IMPLEMENT_API_ERR_EXCEPTION(InvalidPropertyGroupErrorException, files::InvalidPropertyGroupError);
IMPLEMENT_API_ERR_EXCEPTION(RemovePropertiesErrorException, files::RemovePropertiesError);
IMPLEMENT_API_ERR_EXCEPTION(PropertyTemplateErrorException, properties::PropertyTemplateError);
IMPLEMENT_API_ERR_EXCEPTION(UpdatePropertiesErrorException, files::UpdatePropertiesError);
IMPLEMENT_API_ERR_EXCEPTION(RestoreErrorException, files::RestoreError);
IMPLEMENT_API_ERR_EXCEPTION(SaveUrlErrorException, files::SaveUrlError);
IMPLEMENT_API_ERR_EXCEPTION(PollErrorException, async::PollError);
IMPLEMENT_API_ERR_EXCEPTION(SearchErrorException, files::SearchError);
IMPLEMENT_API_ERR_EXCEPTION(UploadErrorException, files::UploadError);
IMPLEMENT_API_ERR_EXCEPTION(UploadSessionLookupErrorException, files::UploadSessionLookupError);
IMPLEMENT_API_ERR_EXCEPTION(UploadSessionFinishErrorException, files::UploadSessionFinishError);
