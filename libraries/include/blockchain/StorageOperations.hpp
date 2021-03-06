#pragma once

#include <blockchain/ContractEntry.hpp>
#include <blockchain/Operations.hpp>

namespace TiValue {
    namespace blockchain {

        struct StorageDataChangeType
        {
            StorageDataType storage_before;
            StorageDataType storage_after;
        };

        struct StorageOperation
        {
            static const OperationTypeEnum type;

            StorageOperation(){}

            ContractIdType contract_id;
            std::map<std::string, StorageDataChangeType> contract_change_storages;

            template<typename StorageBaseType, typename StorageContainerType>
            void update_contract_map_storage(const StorageDataChangeType& change_storage, StorageDataType& storage)const;

            //void update_contract_storages(const StorageDataChangeType& change_storage, StorageDataType& storage)const;
            void update_contract_storages(const std::string storage_name, const StorageDataChangeType& change_storage,
                std::map<std::string, StorageDataType>& contract_storages)const;

            void evaluate(TransactionEvaluationState& eval_state)const;
        };

    }
} // TiValue::blockchain


FC_REFLECT(TiValue::blockchain::StorageDataChangeType, (storage_before)(storage_after))
FC_REFLECT(TiValue::blockchain::StorageOperation, (contract_id)(contract_change_storages))
