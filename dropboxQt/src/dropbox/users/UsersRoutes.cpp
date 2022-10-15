/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/users/UsersRoutes.h"
#include "dropbox/endpoint/Endpoint.h"
using namespace dropboxQt;
using namespace users;

std::unique_ptr<BasicAccount> UsersRoutes::getAccount(const GetAccountArg& arg ){
    return getAccount_Async(arg)->waitForResultAndRelease();
}

DropboxTask<BasicAccount>* UsersRoutes::getAccount_Async(const GetAccountArg& arg)
{
    DropboxTask<BasicAccount>* t = m_end_point->produceTask<BasicAccount>();
    m_end_point->rpcStyle<
        GetAccountArg,
        BasicAccount,
        BasicAccount::factory,
        GetAccountErrorException>
        ("2/users/get_account",
        arg,
        t);
    return t;
}

void UsersRoutes::getAccount_AsyncCB(
    const GetAccountArg& arg,
    std::function<void(std::unique_ptr<BasicAccount>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        GetAccountArg,
        BasicAccount,
        BasicAccount::factory,
        GetAccountErrorException>
        ("2/users/get_account",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<std::list <BasicAccount>> UsersRoutes::getAccountBatch(const GetAccountBatchArg& arg ){
    return getAccountBatch_Async(arg)->waitForResultAndRelease();
}

DropboxTask<std::list <BasicAccount>>* UsersRoutes::getAccountBatch_Async(const GetAccountBatchArg& arg)
{
    DropboxTask<std::list <BasicAccount>>* t = m_end_point->produceTask<std::list <BasicAccount>>();
    m_end_point->rpcStyle<
        GetAccountBatchArg,
        std::list <BasicAccount>,
        ListFromJsonLoader<std::list <BasicAccount>, BasicAccount>,
        GetAccountBatchErrorException>
        ("2/users/get_account_batch",
        arg,
        t);
    return t;
}

void UsersRoutes::getAccountBatch_AsyncCB(
    const GetAccountBatchArg& arg,
    std::function<void(std::unique_ptr<std::list <BasicAccount>>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        GetAccountBatchArg,
        std::list <BasicAccount>,
        ListFromJsonLoader<std::list <BasicAccount>, BasicAccount>,
        GetAccountBatchErrorException>
        ("2/users/get_account_batch",
        arg,
        completed_callback,
        failed_callback);
}

std::unique_ptr<FullAccount> UsersRoutes::getCurrentAccount(void){
    return getCurrentAccount_Async()->waitForResultAndRelease();
}

DropboxTask<FullAccount>* UsersRoutes::getCurrentAccount_Async()
{
    DropboxTask<FullAccount>* t = m_end_point->produceTask<FullAccount>();
    m_end_point->rpcStyle<
        FullAccount,
        FullAccount::factory,
        DropboxException>
        ("2/users/get_current_account",
        t);
    return t;
}

void UsersRoutes::getCurrentAccount_AsyncCB(
    std::function<void(std::unique_ptr<FullAccount>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        FullAccount,
        FullAccount::factory,
        DropboxException>
        ("2/users/get_current_account",
        completed_callback,
        failed_callback);
}

std::unique_ptr<SpaceUsage> UsersRoutes::getSpaceUsage(void){
    return getSpaceUsage_Async()->waitForResultAndRelease();
}

DropboxTask<SpaceUsage>* UsersRoutes::getSpaceUsage_Async()
{
    DropboxTask<SpaceUsage>* t = m_end_point->produceTask<SpaceUsage>();
    m_end_point->rpcStyle<
        SpaceUsage,
        SpaceUsage::factory,
        DropboxException>
        ("2/users/get_space_usage",
        t);
    return t;
}

void UsersRoutes::getSpaceUsage_AsyncCB(
    std::function<void(std::unique_ptr<SpaceUsage>)> completed_callback ,
    std::function<void(std::unique_ptr<DropboxException>)> failed_callback)
{
    m_end_point->rpcStyle<
        SpaceUsage,
        SpaceUsage::factory,
        DropboxException>
        ("2/users/get_space_usage",
        completed_callback,
        failed_callback);
}

IMPLEMENT_API_ERR_EXCEPTION(GetAccountErrorException, users::GetAccountError);
IMPLEMENT_API_ERR_EXCEPTION(GetAccountBatchErrorException, users::GetAccountBatchError);
