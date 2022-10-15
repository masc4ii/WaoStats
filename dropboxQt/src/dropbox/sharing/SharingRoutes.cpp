/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingRoutes.h"
#include "dropbox/endpoint/Endpoint.h"
using namespace dropboxQt;
using namespace sharing;

std::unique_ptr<std::list <FileMemberActionResult>> SharingRoutes::addFileMember(const AddFileMemberArgs& arg ){
    return addFileMember_Async(arg)->waitForResultAndRelease();
}

DropboxTask<std::list <FileMemberActionResult>>* SharingRoutes::addFileMember_Async(const AddFileMemberArgs& arg)
{
    DropboxTask<std::list <FileMemberActionResult>>* t = m_end_point->produceTask<std::list <FileMemberActionResult>>();
    m_end_point->rpcStyle<
        AddFileMemberArgs,
        std::list <FileMemberActionResult>,
        ListFromJsonLoader<std::list <FileMemberActionResult>, FileMemberActionResult>,
        AddFileMemberErrorException>
        ("2/sharing/add_file_member",
        arg,
        t);
    return t;
}

void SharingRoutes::addFileMember_AsyncCB(
    const AddFileMemberArgs& arg,
    std::function<void(std::unique_ptr<std::list <FileMemberActionResult>>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        AddFileMemberArgs,
        std::list <FileMemberActionResult>,
        ListFromJsonLoader<std::list <FileMemberActionResult>, FileMemberActionResult>,
        AddFileMemberErrorException>
        ("2/sharing/add_file_member",
        arg,
        completed_callback,
        failed_callback);
}

void SharingRoutes::addFolderMember(const AddFolderMemberArg& arg ){
    addFolderMember_Async(arg)->waitForResultAndRelease();
}

DropboxVoidTask* SharingRoutes::addFolderMember_Async(const AddFolderMemberArg& arg)
{
    DropboxVoidTask* t = m_end_point->produceVoidTask();
    m_end_point->rpcStyle<
        AddFolderMemberArg,
        AddFolderMemberErrorException>
        ("2/sharing/add_folder_member",
        arg,
        t);
    return t;
}

void SharingRoutes::addFolderMember_AsyncCB(
    const AddFolderMemberArg& arg,
    std::function<void()> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        AddFolderMemberArg,
        AddFolderMemberErrorException>
        ("2/sharing/add_folder_member",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<FileMemberActionResult> SharingRoutes::changeFileMemberAccess(const ChangeFileMemberAccessArgs& arg ){
    return changeFileMemberAccess_Async(arg)->waitForResultAndRelease();
}

DropboxTask<FileMemberActionResult>* SharingRoutes::changeFileMemberAccess_Async(const ChangeFileMemberAccessArgs& arg)
{
    DropboxTask<FileMemberActionResult>* t = m_end_point->produceTask<FileMemberActionResult>();
    m_end_point->rpcStyle<
        ChangeFileMemberAccessArgs,
        FileMemberActionResult,
        FileMemberActionResult::factory,
        FileMemberActionErrorException>
        ("2/sharing/change_file_member_access",
        arg,
        t);
    return t;
}

void SharingRoutes::changeFileMemberAccess_AsyncCB(
    const ChangeFileMemberAccessArgs& arg,
    std::function<void(std::unique_ptr<FileMemberActionResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        ChangeFileMemberAccessArgs,
        FileMemberActionResult,
        FileMemberActionResult::factory,
        FileMemberActionErrorException>
        ("2/sharing/change_file_member_access",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<JobStatus> SharingRoutes::checkJobStatus(const async::PollArg& arg ){
    return checkJobStatus_Async(arg)->waitForResultAndRelease();
}

DropboxTask<JobStatus>* SharingRoutes::checkJobStatus_Async(const async::PollArg& arg)
{
    DropboxTask<JobStatus>* t = m_end_point->produceTask<JobStatus>();
    m_end_point->rpcStyle<
        async::PollArg,
        JobStatus,
        JobStatus::factory,
        PollErrorException>
        ("2/sharing/check_job_status",
        arg,
        t);
    return t;
}

void SharingRoutes::checkJobStatus_AsyncCB(
    const async::PollArg& arg,
    std::function<void(std::unique_ptr<JobStatus>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        async::PollArg,
        JobStatus,
        JobStatus::factory,
        PollErrorException>
        ("2/sharing/check_job_status",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<RemoveMemberJobStatus> SharingRoutes::checkRemoveMemberJobStatus(const async::PollArg& arg ){
    return checkRemoveMemberJobStatus_Async(arg)->waitForResultAndRelease();
}

DropboxTask<RemoveMemberJobStatus>* SharingRoutes::checkRemoveMemberJobStatus_Async(const async::PollArg& arg)
{
    DropboxTask<RemoveMemberJobStatus>* t = m_end_point->produceTask<RemoveMemberJobStatus>();
    m_end_point->rpcStyle<
        async::PollArg,
        RemoveMemberJobStatus,
        RemoveMemberJobStatus::factory,
        PollErrorException>
        ("2/sharing/check_remove_member_job_status",
        arg,
        t);
    return t;
}

void SharingRoutes::checkRemoveMemberJobStatus_AsyncCB(
    const async::PollArg& arg,
    std::function<void(std::unique_ptr<RemoveMemberJobStatus>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        async::PollArg,
        RemoveMemberJobStatus,
        RemoveMemberJobStatus::factory,
        PollErrorException>
        ("2/sharing/check_remove_member_job_status",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<ShareFolderJobStatus> SharingRoutes::checkShareJobStatus(const async::PollArg& arg ){
    return checkShareJobStatus_Async(arg)->waitForResultAndRelease();
}

DropboxTask<ShareFolderJobStatus>* SharingRoutes::checkShareJobStatus_Async(const async::PollArg& arg)
{
    DropboxTask<ShareFolderJobStatus>* t = m_end_point->produceTask<ShareFolderJobStatus>();
    m_end_point->rpcStyle<
        async::PollArg,
        ShareFolderJobStatus,
        ShareFolderJobStatus::factory,
        PollErrorException>
        ("2/sharing/check_share_job_status",
        arg,
        t);
    return t;
}

void SharingRoutes::checkShareJobStatus_AsyncCB(
    const async::PollArg& arg,
    std::function<void(std::unique_ptr<ShareFolderJobStatus>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        async::PollArg,
        ShareFolderJobStatus,
        ShareFolderJobStatus::factory,
        PollErrorException>
        ("2/sharing/check_share_job_status",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<PathLinkMetadata> SharingRoutes::createSharedLink(const CreateSharedLinkArg& arg ){
    return createSharedLink_Async(arg)->waitForResultAndRelease();
}

DropboxTask<PathLinkMetadata>* SharingRoutes::createSharedLink_Async(const CreateSharedLinkArg& arg)
{
    DropboxTask<PathLinkMetadata>* t = m_end_point->produceTask<PathLinkMetadata>();
    m_end_point->rpcStyle<
        CreateSharedLinkArg,
        PathLinkMetadata,
        PathLinkMetadata::factory,
        CreateSharedLinkErrorException>
        ("2/sharing/create_shared_link",
        arg,
        t);
    return t;
}

void SharingRoutes::createSharedLink_AsyncCB(
    const CreateSharedLinkArg& arg,
    std::function<void(std::unique_ptr<PathLinkMetadata>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        CreateSharedLinkArg,
        PathLinkMetadata,
        PathLinkMetadata::factory,
        CreateSharedLinkErrorException>
        ("2/sharing/create_shared_link",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<SharedLinkMetadata> SharingRoutes::createSharedLinkWithSettings(const CreateSharedLinkWithSettingsArg& arg ){
    return createSharedLinkWithSettings_Async(arg)->waitForResultAndRelease();
}

DropboxTask<SharedLinkMetadata>* SharingRoutes::createSharedLinkWithSettings_Async(const CreateSharedLinkWithSettingsArg& arg)
{
    DropboxTask<SharedLinkMetadata>* t = m_end_point->produceTask<SharedLinkMetadata>();
    m_end_point->rpcStyle<
        CreateSharedLinkWithSettingsArg,
        SharedLinkMetadata,
        SharedLinkMetadata::factory,
        CreateSharedLinkWithSettingsErrorException>
        ("2/sharing/create_shared_link_with_settings",
        arg,
        t);
    return t;
}

void SharingRoutes::createSharedLinkWithSettings_AsyncCB(
    const CreateSharedLinkWithSettingsArg& arg,
    std::function<void(std::unique_ptr<SharedLinkMetadata>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        CreateSharedLinkWithSettingsArg,
        SharedLinkMetadata,
        SharedLinkMetadata::factory,
        CreateSharedLinkWithSettingsErrorException>
        ("2/sharing/create_shared_link_with_settings",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<SharedFileMetadata> SharingRoutes::getFileMetadata(const GetFileMetadataArg& arg ){
    return getFileMetadata_Async(arg)->waitForResultAndRelease();
}

DropboxTask<SharedFileMetadata>* SharingRoutes::getFileMetadata_Async(const GetFileMetadataArg& arg)
{
    DropboxTask<SharedFileMetadata>* t = m_end_point->produceTask<SharedFileMetadata>();
    m_end_point->rpcStyle<
        GetFileMetadataArg,
        SharedFileMetadata,
        SharedFileMetadata::factory,
        GetFileMetadataErrorException>
        ("2/sharing/get_file_metadata",
        arg,
        t);
    return t;
}

void SharingRoutes::getFileMetadata_AsyncCB(
    const GetFileMetadataArg& arg,
    std::function<void(std::unique_ptr<SharedFileMetadata>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        GetFileMetadataArg,
        SharedFileMetadata,
        SharedFileMetadata::factory,
        GetFileMetadataErrorException>
        ("2/sharing/get_file_metadata",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<std::list <GetFileMetadataBatchResult>> SharingRoutes::getFileMetadataBatch(const GetFileMetadataBatchArg& arg ){
    return getFileMetadataBatch_Async(arg)->waitForResultAndRelease();
}

DropboxTask<std::list <GetFileMetadataBatchResult>>* SharingRoutes::getFileMetadataBatch_Async(const GetFileMetadataBatchArg& arg)
{
    DropboxTask<std::list <GetFileMetadataBatchResult>>* t = m_end_point->produceTask<std::list <GetFileMetadataBatchResult>>();
    m_end_point->rpcStyle<
        GetFileMetadataBatchArg,
        std::list <GetFileMetadataBatchResult>,
        ListFromJsonLoader<std::list <GetFileMetadataBatchResult>, GetFileMetadataBatchResult>,
        SharingUserErrorException>
        ("2/sharing/get_file_metadata/batch",
        arg,
        t);
    return t;
}

void SharingRoutes::getFileMetadataBatch_AsyncCB(
    const GetFileMetadataBatchArg& arg,
    std::function<void(std::unique_ptr<std::list <GetFileMetadataBatchResult>>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        GetFileMetadataBatchArg,
        std::list <GetFileMetadataBatchResult>,
        ListFromJsonLoader<std::list <GetFileMetadataBatchResult>, GetFileMetadataBatchResult>,
        SharingUserErrorException>
        ("2/sharing/get_file_metadata/batch",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<SharedFolderMetadata> SharingRoutes::getFolderMetadata(const GetMetadataArgs& arg ){
    return getFolderMetadata_Async(arg)->waitForResultAndRelease();
}

DropboxTask<SharedFolderMetadata>* SharingRoutes::getFolderMetadata_Async(const GetMetadataArgs& arg)
{
    DropboxTask<SharedFolderMetadata>* t = m_end_point->produceTask<SharedFolderMetadata>();
    m_end_point->rpcStyle<
        GetMetadataArgs,
        SharedFolderMetadata,
        SharedFolderMetadata::factory,
        SharedFolderAccessErrorException>
        ("2/sharing/get_folder_metadata",
        arg,
        t);
    return t;
}

void SharingRoutes::getFolderMetadata_AsyncCB(
    const GetMetadataArgs& arg,
    std::function<void(std::unique_ptr<SharedFolderMetadata>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        GetMetadataArgs,
        SharedFolderMetadata,
        SharedFolderMetadata::factory,
        SharedFolderAccessErrorException>
        ("2/sharing/get_folder_metadata",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<SharedLinkMetadata> SharingRoutes::getSharedLinkFile(const GetSharedLinkMetadataArg& arg , QIODevice* data){
    return getSharedLinkFile_Async(arg, data)->waitForResultAndRelease();
}

DropboxTask<SharedLinkMetadata>* SharingRoutes::getSharedLinkFile_Async(const GetSharedLinkMetadataArg& arg, QIODevice* data)
{
    DropboxTask<SharedLinkMetadata>* t = m_end_point->produceTask<SharedLinkMetadata>();
    m_end_point->downloadStyle<
        GetSharedLinkMetadataArg,
        SharedLinkMetadata,
        SharedLinkMetadata::factory,
        GetSharedLinkFileErrorException>
        ("2/sharing/get_shared_link_file",
        arg,
        data,
        t);
    return t;
}

void SharingRoutes::getSharedLinkFile_AsyncCB(
    const GetSharedLinkMetadataArg& arg,
    QIODevice* data,
    std::function<void(std::unique_ptr<SharedLinkMetadata>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->downloadStyle<
        GetSharedLinkMetadataArg,
        SharedLinkMetadata,
        SharedLinkMetadata::factory,
        GetSharedLinkFileErrorException>
        ("2/sharing/get_shared_link_file",
        arg,
        data,
        completed_callback,
        failed_callback);
}

std::unique_ptr<SharedLinkMetadata> SharingRoutes::getSharedLinkMetadata(const GetSharedLinkMetadataArg& arg ){
    return getSharedLinkMetadata_Async(arg)->waitForResultAndRelease();
}

DropboxTask<SharedLinkMetadata>* SharingRoutes::getSharedLinkMetadata_Async(const GetSharedLinkMetadataArg& arg)
{
    DropboxTask<SharedLinkMetadata>* t = m_end_point->produceTask<SharedLinkMetadata>();
    m_end_point->rpcStyle<
        GetSharedLinkMetadataArg,
        SharedLinkMetadata,
        SharedLinkMetadata::factory,
        SharedLinkErrorException>
        ("2/sharing/get_shared_link_metadata",
        arg,
        t);
    return t;
}

void SharingRoutes::getSharedLinkMetadata_AsyncCB(
    const GetSharedLinkMetadataArg& arg,
    std::function<void(std::unique_ptr<SharedLinkMetadata>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        GetSharedLinkMetadataArg,
        SharedLinkMetadata,
        SharedLinkMetadata::factory,
        SharedLinkErrorException>
        ("2/sharing/get_shared_link_metadata",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<GetSharedLinksResult> SharingRoutes::getSharedLinks(const GetSharedLinksArg& arg ){
    return getSharedLinks_Async(arg)->waitForResultAndRelease();
}

DropboxTask<GetSharedLinksResult>* SharingRoutes::getSharedLinks_Async(const GetSharedLinksArg& arg)
{
    DropboxTask<GetSharedLinksResult>* t = m_end_point->produceTask<GetSharedLinksResult>();
    m_end_point->rpcStyle<
        GetSharedLinksArg,
        GetSharedLinksResult,
        GetSharedLinksResult::factory,
        GetSharedLinksErrorException>
        ("2/sharing/get_shared_links",
        arg,
        t);
    return t;
}

void SharingRoutes::getSharedLinks_AsyncCB(
    const GetSharedLinksArg& arg,
    std::function<void(std::unique_ptr<GetSharedLinksResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        GetSharedLinksArg,
        GetSharedLinksResult,
        GetSharedLinksResult::factory,
        GetSharedLinksErrorException>
        ("2/sharing/get_shared_links",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<SharedFileMembers> SharingRoutes::listFileMembers(const ListFileMembersArg& arg ){
    return listFileMembers_Async(arg)->waitForResultAndRelease();
}

DropboxTask<SharedFileMembers>* SharingRoutes::listFileMembers_Async(const ListFileMembersArg& arg)
{
    DropboxTask<SharedFileMembers>* t = m_end_point->produceTask<SharedFileMembers>();
    m_end_point->rpcStyle<
        ListFileMembersArg,
        SharedFileMembers,
        SharedFileMembers::factory,
        ListFileMembersErrorException>
        ("2/sharing/list_file_members",
        arg,
        t);
    return t;
}

void SharingRoutes::listFileMembers_AsyncCB(
    const ListFileMembersArg& arg,
    std::function<void(std::unique_ptr<SharedFileMembers>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        ListFileMembersArg,
        SharedFileMembers,
        SharedFileMembers::factory,
        ListFileMembersErrorException>
        ("2/sharing/list_file_members",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<std::list <ListFileMembersBatchResult>> SharingRoutes::listFileMembersBatch(const ListFileMembersBatchArg& arg ){
    return listFileMembersBatch_Async(arg)->waitForResultAndRelease();
}

DropboxTask<std::list <ListFileMembersBatchResult>>* SharingRoutes::listFileMembersBatch_Async(const ListFileMembersBatchArg& arg)
{
    DropboxTask<std::list <ListFileMembersBatchResult>>* t = m_end_point->produceTask<std::list <ListFileMembersBatchResult>>();
    m_end_point->rpcStyle<
        ListFileMembersBatchArg,
        std::list <ListFileMembersBatchResult>,
        ListFromJsonLoader<std::list <ListFileMembersBatchResult>, ListFileMembersBatchResult>,
        SharingUserErrorException>
        ("2/sharing/list_file_members/batch",
        arg,
        t);
    return t;
}

void SharingRoutes::listFileMembersBatch_AsyncCB(
    const ListFileMembersBatchArg& arg,
    std::function<void(std::unique_ptr<std::list <ListFileMembersBatchResult>>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        ListFileMembersBatchArg,
        std::list <ListFileMembersBatchResult>,
        ListFromJsonLoader<std::list <ListFileMembersBatchResult>, ListFileMembersBatchResult>,
        SharingUserErrorException>
        ("2/sharing/list_file_members/batch",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<SharedFileMembers> SharingRoutes::listFileMembersContinue(const ListFileMembersContinueArg& arg ){
    return listFileMembersContinue_Async(arg)->waitForResultAndRelease();
}

DropboxTask<SharedFileMembers>* SharingRoutes::listFileMembersContinue_Async(const ListFileMembersContinueArg& arg)
{
    DropboxTask<SharedFileMembers>* t = m_end_point->produceTask<SharedFileMembers>();
    m_end_point->rpcStyle<
        ListFileMembersContinueArg,
        SharedFileMembers,
        SharedFileMembers::factory,
        ListFileMembersContinueErrorException>
        ("2/sharing/list_file_members/continue",
        arg,
        t);
    return t;
}

void SharingRoutes::listFileMembersContinue_AsyncCB(
    const ListFileMembersContinueArg& arg,
    std::function<void(std::unique_ptr<SharedFileMembers>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        ListFileMembersContinueArg,
        SharedFileMembers,
        SharedFileMembers::factory,
        ListFileMembersContinueErrorException>
        ("2/sharing/list_file_members/continue",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<SharedFolderMembers> SharingRoutes::listFolderMembers(const ListFolderMembersArgs& arg ){
    return listFolderMembers_Async(arg)->waitForResultAndRelease();
}

DropboxTask<SharedFolderMembers>* SharingRoutes::listFolderMembers_Async(const ListFolderMembersArgs& arg)
{
    DropboxTask<SharedFolderMembers>* t = m_end_point->produceTask<SharedFolderMembers>();
    m_end_point->rpcStyle<
        ListFolderMembersArgs,
        SharedFolderMembers,
        SharedFolderMembers::factory,
        SharedFolderAccessErrorException>
        ("2/sharing/list_folder_members",
        arg,
        t);
    return t;
}

void SharingRoutes::listFolderMembers_AsyncCB(
    const ListFolderMembersArgs& arg,
    std::function<void(std::unique_ptr<SharedFolderMembers>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        ListFolderMembersArgs,
        SharedFolderMembers,
        SharedFolderMembers::factory,
        SharedFolderAccessErrorException>
        ("2/sharing/list_folder_members",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<SharedFolderMembers> SharingRoutes::listFolderMembersContinue(const ListFolderMembersContinueArg& arg ){
    return listFolderMembersContinue_Async(arg)->waitForResultAndRelease();
}

DropboxTask<SharedFolderMembers>* SharingRoutes::listFolderMembersContinue_Async(const ListFolderMembersContinueArg& arg)
{
    DropboxTask<SharedFolderMembers>* t = m_end_point->produceTask<SharedFolderMembers>();
    m_end_point->rpcStyle<
        ListFolderMembersContinueArg,
        SharedFolderMembers,
        SharedFolderMembers::factory,
        ListFolderMembersContinueErrorException>
        ("2/sharing/list_folder_members/continue",
        arg,
        t);
    return t;
}

void SharingRoutes::listFolderMembersContinue_AsyncCB(
    const ListFolderMembersContinueArg& arg,
    std::function<void(std::unique_ptr<SharedFolderMembers>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        ListFolderMembersContinueArg,
        SharedFolderMembers,
        SharedFolderMembers::factory,
        ListFolderMembersContinueErrorException>
        ("2/sharing/list_folder_members/continue",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<ListFoldersResult> SharingRoutes::listFolders(const ListFoldersArgs& arg ){
    return listFolders_Async(arg)->waitForResultAndRelease();
}

DropboxTask<ListFoldersResult>* SharingRoutes::listFolders_Async(const ListFoldersArgs& arg)
{
    DropboxTask<ListFoldersResult>* t = m_end_point->produceTask<ListFoldersResult>();
    m_end_point->rpcStyle<
        ListFoldersArgs,
        ListFoldersResult,
        ListFoldersResult::factory,
        DropboxException>
        ("2/sharing/list_folders",
        arg,
        t);
    return t;
}

void SharingRoutes::listFolders_AsyncCB(
    const ListFoldersArgs& arg,
    std::function<void(std::unique_ptr<ListFoldersResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        ListFoldersArgs,
        ListFoldersResult,
        ListFoldersResult::factory,
        DropboxException>
        ("2/sharing/list_folders",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<ListFoldersResult> SharingRoutes::listFoldersContinue(const ListFoldersContinueArg& arg ){
    return listFoldersContinue_Async(arg)->waitForResultAndRelease();
}

DropboxTask<ListFoldersResult>* SharingRoutes::listFoldersContinue_Async(const ListFoldersContinueArg& arg)
{
    DropboxTask<ListFoldersResult>* t = m_end_point->produceTask<ListFoldersResult>();
    m_end_point->rpcStyle<
        ListFoldersContinueArg,
        ListFoldersResult,
        ListFoldersResult::factory,
        ListFoldersContinueErrorException>
        ("2/sharing/list_folders/continue",
        arg,
        t);
    return t;
}

void SharingRoutes::listFoldersContinue_AsyncCB(
    const ListFoldersContinueArg& arg,
    std::function<void(std::unique_ptr<ListFoldersResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        ListFoldersContinueArg,
        ListFoldersResult,
        ListFoldersResult::factory,
        ListFoldersContinueErrorException>
        ("2/sharing/list_folders/continue",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<ListFoldersResult> SharingRoutes::listMountableFolders(const ListFoldersArgs& arg ){
    return listMountableFolders_Async(arg)->waitForResultAndRelease();
}

DropboxTask<ListFoldersResult>* SharingRoutes::listMountableFolders_Async(const ListFoldersArgs& arg)
{
    DropboxTask<ListFoldersResult>* t = m_end_point->produceTask<ListFoldersResult>();
    m_end_point->rpcStyle<
        ListFoldersArgs,
        ListFoldersResult,
        ListFoldersResult::factory,
        DropboxException>
        ("2/sharing/list_mountable_folders",
        arg,
        t);
    return t;
}

void SharingRoutes::listMountableFolders_AsyncCB(
    const ListFoldersArgs& arg,
    std::function<void(std::unique_ptr<ListFoldersResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        ListFoldersArgs,
        ListFoldersResult,
        ListFoldersResult::factory,
        DropboxException>
        ("2/sharing/list_mountable_folders",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<ListFoldersResult> SharingRoutes::listMountableFoldersContinue(const ListFoldersContinueArg& arg ){
    return listMountableFoldersContinue_Async(arg)->waitForResultAndRelease();
}

DropboxTask<ListFoldersResult>* SharingRoutes::listMountableFoldersContinue_Async(const ListFoldersContinueArg& arg)
{
    DropboxTask<ListFoldersResult>* t = m_end_point->produceTask<ListFoldersResult>();
    m_end_point->rpcStyle<
        ListFoldersContinueArg,
        ListFoldersResult,
        ListFoldersResult::factory,
        ListFoldersContinueErrorException>
        ("2/sharing/list_mountable_folders/continue",
        arg,
        t);
    return t;
}

void SharingRoutes::listMountableFoldersContinue_AsyncCB(
    const ListFoldersContinueArg& arg,
    std::function<void(std::unique_ptr<ListFoldersResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        ListFoldersContinueArg,
        ListFoldersResult,
        ListFoldersResult::factory,
        ListFoldersContinueErrorException>
        ("2/sharing/list_mountable_folders/continue",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<ListFilesResult> SharingRoutes::listReceivedFiles(const ListFilesArg& arg ){
    return listReceivedFiles_Async(arg)->waitForResultAndRelease();
}

DropboxTask<ListFilesResult>* SharingRoutes::listReceivedFiles_Async(const ListFilesArg& arg)
{
    DropboxTask<ListFilesResult>* t = m_end_point->produceTask<ListFilesResult>();
    m_end_point->rpcStyle<
        ListFilesArg,
        ListFilesResult,
        ListFilesResult::factory,
        SharingUserErrorException>
        ("2/sharing/list_received_files",
        arg,
        t);
    return t;
}

void SharingRoutes::listReceivedFiles_AsyncCB(
    const ListFilesArg& arg,
    std::function<void(std::unique_ptr<ListFilesResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        ListFilesArg,
        ListFilesResult,
        ListFilesResult::factory,
        SharingUserErrorException>
        ("2/sharing/list_received_files",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<ListFilesResult> SharingRoutes::listReceivedFilesContinue(const ListFilesContinueArg& arg ){
    return listReceivedFilesContinue_Async(arg)->waitForResultAndRelease();
}

DropboxTask<ListFilesResult>* SharingRoutes::listReceivedFilesContinue_Async(const ListFilesContinueArg& arg)
{
    DropboxTask<ListFilesResult>* t = m_end_point->produceTask<ListFilesResult>();
    m_end_point->rpcStyle<
        ListFilesContinueArg,
        ListFilesResult,
        ListFilesResult::factory,
        ListFilesContinueErrorException>
        ("2/sharing/list_received_files/continue",
        arg,
        t);
    return t;
}

void SharingRoutes::listReceivedFilesContinue_AsyncCB(
    const ListFilesContinueArg& arg,
    std::function<void(std::unique_ptr<ListFilesResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        ListFilesContinueArg,
        ListFilesResult,
        ListFilesResult::factory,
        ListFilesContinueErrorException>
        ("2/sharing/list_received_files/continue",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<ListSharedLinksResult> SharingRoutes::listSharedLinks(const ListSharedLinksArg& arg ){
    return listSharedLinks_Async(arg)->waitForResultAndRelease();
}

DropboxTask<ListSharedLinksResult>* SharingRoutes::listSharedLinks_Async(const ListSharedLinksArg& arg)
{
    DropboxTask<ListSharedLinksResult>* t = m_end_point->produceTask<ListSharedLinksResult>();
    m_end_point->rpcStyle<
        ListSharedLinksArg,
        ListSharedLinksResult,
        ListSharedLinksResult::factory,
        ListSharedLinksErrorException>
        ("2/sharing/list_shared_links",
        arg,
        t);
    return t;
}

void SharingRoutes::listSharedLinks_AsyncCB(
    const ListSharedLinksArg& arg,
    std::function<void(std::unique_ptr<ListSharedLinksResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        ListSharedLinksArg,
        ListSharedLinksResult,
        ListSharedLinksResult::factory,
        ListSharedLinksErrorException>
        ("2/sharing/list_shared_links",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<SharedLinkMetadata> SharingRoutes::modifySharedLinkSettings(const ModifySharedLinkSettingsArgs& arg ){
    return modifySharedLinkSettings_Async(arg)->waitForResultAndRelease();
}

DropboxTask<SharedLinkMetadata>* SharingRoutes::modifySharedLinkSettings_Async(const ModifySharedLinkSettingsArgs& arg)
{
    DropboxTask<SharedLinkMetadata>* t = m_end_point->produceTask<SharedLinkMetadata>();
    m_end_point->rpcStyle<
        ModifySharedLinkSettingsArgs,
        SharedLinkMetadata,
        SharedLinkMetadata::factory,
        ModifySharedLinkSettingsErrorException>
        ("2/sharing/modify_shared_link_settings",
        arg,
        t);
    return t;
}

void SharingRoutes::modifySharedLinkSettings_AsyncCB(
    const ModifySharedLinkSettingsArgs& arg,
    std::function<void(std::unique_ptr<SharedLinkMetadata>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        ModifySharedLinkSettingsArgs,
        SharedLinkMetadata,
        SharedLinkMetadata::factory,
        ModifySharedLinkSettingsErrorException>
        ("2/sharing/modify_shared_link_settings",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<SharedFolderMetadata> SharingRoutes::mountFolder(const MountFolderArg& arg ){
    return mountFolder_Async(arg)->waitForResultAndRelease();
}

DropboxTask<SharedFolderMetadata>* SharingRoutes::mountFolder_Async(const MountFolderArg& arg)
{
    DropboxTask<SharedFolderMetadata>* t = m_end_point->produceTask<SharedFolderMetadata>();
    m_end_point->rpcStyle<
        MountFolderArg,
        SharedFolderMetadata,
        SharedFolderMetadata::factory,
        MountFolderErrorException>
        ("2/sharing/mount_folder",
        arg,
        t);
    return t;
}

void SharingRoutes::mountFolder_AsyncCB(
    const MountFolderArg& arg,
    std::function<void(std::unique_ptr<SharedFolderMetadata>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        MountFolderArg,
        SharedFolderMetadata,
        SharedFolderMetadata::factory,
        MountFolderErrorException>
        ("2/sharing/mount_folder",
        arg,
        completed_callback,
        failed_callback);
}

void SharingRoutes::relinquishFileMembership(const RelinquishFileMembershipArg& arg ){
    relinquishFileMembership_Async(arg)->waitForResultAndRelease();
}

DropboxVoidTask* SharingRoutes::relinquishFileMembership_Async(const RelinquishFileMembershipArg& arg)
{
    DropboxVoidTask* t = m_end_point->produceVoidTask();
    m_end_point->rpcStyle<
        RelinquishFileMembershipArg,
        RelinquishFileMembershipErrorException>
        ("2/sharing/relinquish_file_membership",
        arg,
        t);
    return t;
}

void SharingRoutes::relinquishFileMembership_AsyncCB(
    const RelinquishFileMembershipArg& arg,
    std::function<void()> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        RelinquishFileMembershipArg,
        RelinquishFileMembershipErrorException>
        ("2/sharing/relinquish_file_membership",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<async::LaunchEmptyResult> SharingRoutes::relinquishFolderMembership(const RelinquishFolderMembershipArg& arg ){
    return relinquishFolderMembership_Async(arg)->waitForResultAndRelease();
}

DropboxTask<async::LaunchEmptyResult>* SharingRoutes::relinquishFolderMembership_Async(const RelinquishFolderMembershipArg& arg)
{
    DropboxTask<async::LaunchEmptyResult>* t = m_end_point->produceTask<async::LaunchEmptyResult>();
    m_end_point->rpcStyle<
        RelinquishFolderMembershipArg,
        async::LaunchEmptyResult,
        async::LaunchEmptyResult::factory,
        RelinquishFolderMembershipErrorException>
        ("2/sharing/relinquish_folder_membership",
        arg,
        t);
    return t;
}

void SharingRoutes::relinquishFolderMembership_AsyncCB(
    const RelinquishFolderMembershipArg& arg,
    std::function<void(std::unique_ptr<async::LaunchEmptyResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        RelinquishFolderMembershipArg,
        async::LaunchEmptyResult,
        async::LaunchEmptyResult::factory,
        RelinquishFolderMembershipErrorException>
        ("2/sharing/relinquish_folder_membership",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<FileMemberActionIndividualResult> SharingRoutes::removeFileMember(const RemoveFileMemberArg& arg ){
    return removeFileMember_Async(arg)->waitForResultAndRelease();
}

DropboxTask<FileMemberActionIndividualResult>* SharingRoutes::removeFileMember_Async(const RemoveFileMemberArg& arg)
{
    DropboxTask<FileMemberActionIndividualResult>* t = m_end_point->produceTask<FileMemberActionIndividualResult>();
    m_end_point->rpcStyle<
        RemoveFileMemberArg,
        FileMemberActionIndividualResult,
        FileMemberActionIndividualResult::factory,
        RemoveFileMemberErrorException>
        ("2/sharing/remove_file_member",
        arg,
        t);
    return t;
}

void SharingRoutes::removeFileMember_AsyncCB(
    const RemoveFileMemberArg& arg,
    std::function<void(std::unique_ptr<FileMemberActionIndividualResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        RemoveFileMemberArg,
        FileMemberActionIndividualResult,
        FileMemberActionIndividualResult::factory,
        RemoveFileMemberErrorException>
        ("2/sharing/remove_file_member",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<FileMemberRemoveActionResult> SharingRoutes::removeFileMember2(const RemoveFileMemberArg& arg ){
    return removeFileMember2_Async(arg)->waitForResultAndRelease();
}

DropboxTask<FileMemberRemoveActionResult>* SharingRoutes::removeFileMember2_Async(const RemoveFileMemberArg& arg)
{
    DropboxTask<FileMemberRemoveActionResult>* t = m_end_point->produceTask<FileMemberRemoveActionResult>();
    m_end_point->rpcStyle<
        RemoveFileMemberArg,
        FileMemberRemoveActionResult,
        FileMemberRemoveActionResult::factory,
        RemoveFileMemberErrorException>
        ("2/sharing/remove_file_member_2",
        arg,
        t);
    return t;
}

void SharingRoutes::removeFileMember2_AsyncCB(
    const RemoveFileMemberArg& arg,
    std::function<void(std::unique_ptr<FileMemberRemoveActionResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        RemoveFileMemberArg,
        FileMemberRemoveActionResult,
        FileMemberRemoveActionResult::factory,
        RemoveFileMemberErrorException>
        ("2/sharing/remove_file_member_2",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<async::LaunchResultBase> SharingRoutes::removeFolderMember(const RemoveFolderMemberArg& arg ){
    return removeFolderMember_Async(arg)->waitForResultAndRelease();
}

DropboxTask<async::LaunchResultBase>* SharingRoutes::removeFolderMember_Async(const RemoveFolderMemberArg& arg)
{
    DropboxTask<async::LaunchResultBase>* t = m_end_point->produceTask<async::LaunchResultBase>();
    m_end_point->rpcStyle<
        RemoveFolderMemberArg,
        async::LaunchResultBase,
        async::LaunchResultBase::factory,
        RemoveFolderMemberErrorException>
        ("2/sharing/remove_folder_member",
        arg,
        t);
    return t;
}

void SharingRoutes::removeFolderMember_AsyncCB(
    const RemoveFolderMemberArg& arg,
    std::function<void(std::unique_ptr<async::LaunchResultBase>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        RemoveFolderMemberArg,
        async::LaunchResultBase,
        async::LaunchResultBase::factory,
        RemoveFolderMemberErrorException>
        ("2/sharing/remove_folder_member",
        arg,
        completed_callback,
        failed_callback);
}

void SharingRoutes::revokeSharedLink(const RevokeSharedLinkArg& arg ){
    revokeSharedLink_Async(arg)->waitForResultAndRelease();
}

DropboxVoidTask* SharingRoutes::revokeSharedLink_Async(const RevokeSharedLinkArg& arg)
{
    DropboxVoidTask* t = m_end_point->produceVoidTask();
    m_end_point->rpcStyle<
        RevokeSharedLinkArg,
        RevokeSharedLinkErrorException>
        ("2/sharing/revoke_shared_link",
        arg,
        t);
    return t;
}

void SharingRoutes::revokeSharedLink_AsyncCB(
    const RevokeSharedLinkArg& arg,
    std::function<void()> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        RevokeSharedLinkArg,
        RevokeSharedLinkErrorException>
        ("2/sharing/revoke_shared_link",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<ShareFolderLaunch> SharingRoutes::shareFolder(const ShareFolderArg& arg ){
    return shareFolder_Async(arg)->waitForResultAndRelease();
}

DropboxTask<ShareFolderLaunch>* SharingRoutes::shareFolder_Async(const ShareFolderArg& arg)
{
    DropboxTask<ShareFolderLaunch>* t = m_end_point->produceTask<ShareFolderLaunch>();
    m_end_point->rpcStyle<
        ShareFolderArg,
        ShareFolderLaunch,
        ShareFolderLaunch::factory,
        ShareFolderErrorException>
        ("2/sharing/share_folder",
        arg,
        t);
    return t;
}

void SharingRoutes::shareFolder_AsyncCB(
    const ShareFolderArg& arg,
    std::function<void(std::unique_ptr<ShareFolderLaunch>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        ShareFolderArg,
        ShareFolderLaunch,
        ShareFolderLaunch::factory,
        ShareFolderErrorException>
        ("2/sharing/share_folder",
        arg,
        completed_callback,
        failed_callback);
}

void SharingRoutes::transferFolder(const TransferFolderArg& arg ){
    transferFolder_Async(arg)->waitForResultAndRelease();
}

DropboxVoidTask* SharingRoutes::transferFolder_Async(const TransferFolderArg& arg)
{
    DropboxVoidTask* t = m_end_point->produceVoidTask();
    m_end_point->rpcStyle<
        TransferFolderArg,
        TransferFolderErrorException>
        ("2/sharing/transfer_folder",
        arg,
        t);
    return t;
}

void SharingRoutes::transferFolder_AsyncCB(
    const TransferFolderArg& arg,
    std::function<void()> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        TransferFolderArg,
        TransferFolderErrorException>
        ("2/sharing/transfer_folder",
        arg,
        completed_callback,
        failed_callback);
}

void SharingRoutes::unmountFolder(const UnmountFolderArg& arg ){
    unmountFolder_Async(arg)->waitForResultAndRelease();
}

DropboxVoidTask* SharingRoutes::unmountFolder_Async(const UnmountFolderArg& arg)
{
    DropboxVoidTask* t = m_end_point->produceVoidTask();
    m_end_point->rpcStyle<
        UnmountFolderArg,
        UnmountFolderErrorException>
        ("2/sharing/unmount_folder",
        arg,
        t);
    return t;
}

void SharingRoutes::unmountFolder_AsyncCB(
    const UnmountFolderArg& arg,
    std::function<void()> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        UnmountFolderArg,
        UnmountFolderErrorException>
        ("2/sharing/unmount_folder",
        arg,
        completed_callback,
        failed_callback);
}

void SharingRoutes::unshareFile(const UnshareFileArg& arg ){
    unshareFile_Async(arg)->waitForResultAndRelease();
}

DropboxVoidTask* SharingRoutes::unshareFile_Async(const UnshareFileArg& arg)
{
    DropboxVoidTask* t = m_end_point->produceVoidTask();
    m_end_point->rpcStyle<
        UnshareFileArg,
        UnshareFileErrorException>
        ("2/sharing/unshare_file",
        arg,
        t);
    return t;
}

void SharingRoutes::unshareFile_AsyncCB(
    const UnshareFileArg& arg,
    std::function<void()> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        UnshareFileArg,
        UnshareFileErrorException>
        ("2/sharing/unshare_file",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<async::LaunchEmptyResult> SharingRoutes::unshareFolder(const UnshareFolderArg& arg ){
    return unshareFolder_Async(arg)->waitForResultAndRelease();
}

DropboxTask<async::LaunchEmptyResult>* SharingRoutes::unshareFolder_Async(const UnshareFolderArg& arg)
{
    DropboxTask<async::LaunchEmptyResult>* t = m_end_point->produceTask<async::LaunchEmptyResult>();
    m_end_point->rpcStyle<
        UnshareFolderArg,
        async::LaunchEmptyResult,
        async::LaunchEmptyResult::factory,
        UnshareFolderErrorException>
        ("2/sharing/unshare_folder",
        arg,
        t);
    return t;
}

void SharingRoutes::unshareFolder_AsyncCB(
    const UnshareFolderArg& arg,
    std::function<void(std::unique_ptr<async::LaunchEmptyResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        UnshareFolderArg,
        async::LaunchEmptyResult,
        async::LaunchEmptyResult::factory,
        UnshareFolderErrorException>
        ("2/sharing/unshare_folder",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<MemberAccessLevelResult> SharingRoutes::updateFolderMember(const UpdateFolderMemberArg& arg ){
    return updateFolderMember_Async(arg)->waitForResultAndRelease();
}

DropboxTask<MemberAccessLevelResult>* SharingRoutes::updateFolderMember_Async(const UpdateFolderMemberArg& arg)
{
    DropboxTask<MemberAccessLevelResult>* t = m_end_point->produceTask<MemberAccessLevelResult>();
    m_end_point->rpcStyle<
        UpdateFolderMemberArg,
        MemberAccessLevelResult,
        MemberAccessLevelResult::factory,
        UpdateFolderMemberErrorException>
        ("2/sharing/update_folder_member",
        arg,
        t);
    return t;
}

void SharingRoutes::updateFolderMember_AsyncCB(
    const UpdateFolderMemberArg& arg,
    std::function<void(std::unique_ptr<MemberAccessLevelResult>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        UpdateFolderMemberArg,
        MemberAccessLevelResult,
        MemberAccessLevelResult::factory,
        UpdateFolderMemberErrorException>
        ("2/sharing/update_folder_member",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<SharedFolderMetadata> SharingRoutes::updateFolderPolicy(const UpdateFolderPolicyArg& arg ){
    return updateFolderPolicy_Async(arg)->waitForResultAndRelease();
}

DropboxTask<SharedFolderMetadata>* SharingRoutes::updateFolderPolicy_Async(const UpdateFolderPolicyArg& arg)
{
    DropboxTask<SharedFolderMetadata>* t = m_end_point->produceTask<SharedFolderMetadata>();
    m_end_point->rpcStyle<
        UpdateFolderPolicyArg,
        SharedFolderMetadata,
        SharedFolderMetadata::factory,
        UpdateFolderPolicyErrorException>
        ("2/sharing/update_folder_policy",
        arg,
        t);
    return t;
}

void SharingRoutes::updateFolderPolicy_AsyncCB(
    const UpdateFolderPolicyArg& arg,
    std::function<void(std::unique_ptr<SharedFolderMetadata>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        UpdateFolderPolicyArg,
        SharedFolderMetadata,
        SharedFolderMetadata::factory,
        UpdateFolderPolicyErrorException>
        ("2/sharing/update_folder_policy",
        arg,
        completed_callback,
        failed_callback);
}

IMPLEMENT_API_ERR_EXCEPTION(AddFileMemberErrorException, sharing::AddFileMemberError);
IMPLEMENT_API_ERR_EXCEPTION(AddFolderMemberErrorException, sharing::AddFolderMemberError);
IMPLEMENT_API_ERR_EXCEPTION(FileMemberActionErrorException, sharing::FileMemberActionError);
IMPLEMENT_API_ERR_EXCEPTION(PollErrorException, async::PollError);
IMPLEMENT_API_ERR_EXCEPTION(CreateSharedLinkErrorException, sharing::CreateSharedLinkError);
IMPLEMENT_API_ERR_EXCEPTION(CreateSharedLinkWithSettingsErrorException, sharing::CreateSharedLinkWithSettingsError);
IMPLEMENT_API_ERR_EXCEPTION(GetFileMetadataErrorException, sharing::GetFileMetadataError);
IMPLEMENT_API_ERR_EXCEPTION(SharingUserErrorException, sharing::SharingUserError);
IMPLEMENT_API_ERR_EXCEPTION(SharedFolderAccessErrorException, sharing::SharedFolderAccessError);
IMPLEMENT_API_ERR_EXCEPTION(GetSharedLinkFileErrorException, sharing::GetSharedLinkFileError);
IMPLEMENT_API_ERR_EXCEPTION(SharedLinkErrorException, sharing::SharedLinkError);
IMPLEMENT_API_ERR_EXCEPTION(GetSharedLinksErrorException, sharing::GetSharedLinksError);
IMPLEMENT_API_ERR_EXCEPTION(ListFileMembersErrorException, sharing::ListFileMembersError);
IMPLEMENT_API_ERR_EXCEPTION(ListFileMembersContinueErrorException, sharing::ListFileMembersContinueError);
IMPLEMENT_API_ERR_EXCEPTION(ListFolderMembersContinueErrorException, sharing::ListFolderMembersContinueError);
IMPLEMENT_API_ERR_EXCEPTION(ListFoldersContinueErrorException, sharing::ListFoldersContinueError);
IMPLEMENT_API_ERR_EXCEPTION(ListFilesContinueErrorException, sharing::ListFilesContinueError);
IMPLEMENT_API_ERR_EXCEPTION(ListSharedLinksErrorException, sharing::ListSharedLinksError);
IMPLEMENT_API_ERR_EXCEPTION(ModifySharedLinkSettingsErrorException, sharing::ModifySharedLinkSettingsError);
IMPLEMENT_API_ERR_EXCEPTION(MountFolderErrorException, sharing::MountFolderError);
IMPLEMENT_API_ERR_EXCEPTION(RelinquishFileMembershipErrorException, sharing::RelinquishFileMembershipError);
IMPLEMENT_API_ERR_EXCEPTION(RelinquishFolderMembershipErrorException, sharing::RelinquishFolderMembershipError);
IMPLEMENT_API_ERR_EXCEPTION(RemoveFileMemberErrorException, sharing::RemoveFileMemberError);
IMPLEMENT_API_ERR_EXCEPTION(RemoveFolderMemberErrorException, sharing::RemoveFolderMemberError);
IMPLEMENT_API_ERR_EXCEPTION(RevokeSharedLinkErrorException, sharing::RevokeSharedLinkError);
IMPLEMENT_API_ERR_EXCEPTION(ShareFolderErrorException, sharing::ShareFolderError);
IMPLEMENT_API_ERR_EXCEPTION(TransferFolderErrorException, sharing::TransferFolderError);
IMPLEMENT_API_ERR_EXCEPTION(UnmountFolderErrorException, sharing::UnmountFolderError);
IMPLEMENT_API_ERR_EXCEPTION(UnshareFileErrorException, sharing::UnshareFileError);
IMPLEMENT_API_ERR_EXCEPTION(UnshareFolderErrorException, sharing::UnshareFolderError);
IMPLEMENT_API_ERR_EXCEPTION(UpdateFolderMemberErrorException, sharing::UpdateFolderMemberError);
IMPLEMENT_API_ERR_EXCEPTION(UpdateFolderPolicyErrorException, sharing::UpdateFolderPolicyError);
