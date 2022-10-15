/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/DropboxRouteBase.h"
#include "dropbox/users/UsersBasicAccount.h"
#include "dropbox/users/UsersFullAccount.h"
#include "dropbox/users/UsersGetAccountArg.h"
#include "dropbox/users/UsersGetAccountBatchArg.h"
#include "dropbox/users/UsersGetAccountBatchError.h"
#include "dropbox/users/UsersGetAccountError.h"
#include "dropbox/users/UsersSpaceUsage.h"

namespace dropboxQt{
namespace users{

    ///exception GetAccountError for get_account
    DECLARE_API_ERR_EXCEPTION(GetAccountErrorException, users::GetAccountError);

    ///exception GetAccountBatchError for get_account_batch
    DECLARE_API_ERR_EXCEPTION(GetAccountBatchErrorException, users::GetAccountBatchError);


    class UsersRoutes: public DropboxRouteBase{
    public:
        UsersRoutes(Endpoint* ep):DropboxRouteBase(ep){};
            /**
            ApiRoute('get_account')


            Get information about a user's account.

            on error:GetAccountError throws exception GetAccountErrorException
            */
        std::unique_ptr<BasicAccount> getAccount(const GetAccountArg& );
        DropboxTask<BasicAccount>* getAccount_Async(const GetAccountArg&);
        void getAccount_AsyncCB(
            const GetAccountArg&,
            std::function<void(std::unique_ptr<BasicAccount>)> completed_callback = nullptr,
            std::function<void(std::unique_ptr<DropboxException>)> failed_callback = nullptr);

            /**
            ApiRoute('get_account_batch')


            Get information about multiple user accounts.  At most 300 accounts
            may be queried per request.

            on error:GetAccountBatchError throws exception GetAccountBatchErrorException
            */
        std::unique_ptr<std::list <BasicAccount>> getAccountBatch(const GetAccountBatchArg& );
        DropboxTask<std::list <BasicAccount>>* getAccountBatch_Async(const GetAccountBatchArg&);
        void getAccountBatch_AsyncCB(
            const GetAccountBatchArg&,
            std::function<void(std::unique_ptr<std::list <BasicAccount>>)> completed_callback = nullptr,
            std::function<void(std::unique_ptr<DropboxException>)> failed_callback = nullptr);

            /**
            ApiRoute('get_current_account')


            Get information about the current user's account.

            */
        std::unique_ptr<FullAccount> getCurrentAccount();
        DropboxTask<FullAccount>* getCurrentAccount_Async();
        void getCurrentAccount_AsyncCB(
            std::function<void(std::unique_ptr<FullAccount>)> completed_callback = nullptr,
            std::function<void(std::unique_ptr<DropboxException>)> failed_callback = nullptr);

            /**
            ApiRoute('get_space_usage')


            Get the space usage information for the current user's account.

            */
        std::unique_ptr<SpaceUsage> getSpaceUsage();
        DropboxTask<SpaceUsage>* getSpaceUsage_Async();
        void getSpaceUsage_AsyncCB(
            std::function<void(std::unique_ptr<SpaceUsage>)> completed_callback = nullptr,
            std::function<void(std::unique_ptr<DropboxException>)> failed_callback = nullptr);

    protected:
    };//UsersRoutes

}//users
}//dropboxQt
