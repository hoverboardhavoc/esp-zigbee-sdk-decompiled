/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> append_tou_info_set_to_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
append_tou_info_set_to_payload
          (zcl_packet_payload_t *payload,ezb_zcl_metering_tou_info_set_t *tou_info_set)

{
  ezb_zcl_status_t eVar1;
  int iVar2;
  uint32_t auStack_14 [2];
  
  iVar2 = zcl_packet_append_variable_attr_value(0x25,tou_info_set);
  if (iVar2 == 0) {
    auStack_14[0] = tou_info_set->bill_to_date;
    iVar2 = zmsg_append_bytes(payload,4,auStack_14);
    if (iVar2 == 0) {
      auStack_14[0] = tou_info_set->bill_to_date_time_stamp;
      iVar2 = zmsg_append_bytes(payload,4,auStack_14);
      if (iVar2 == 0) {
        auStack_14[0] = tou_info_set->projected_bill;
        iVar2 = zmsg_append_bytes(payload,4,auStack_14);
        if (iVar2 == 0) {
          auStack_14[0] = tou_info_set->projected_bill_time_stamp;
          iVar2 = zmsg_append_bytes(payload,4,auStack_14);
          if (iVar2 == 0) {
            auStack_14[0]._0_1_ = tou_info_set->bill_delivered_trailing_digit;
            iVar2 = zmsg_append_bytes(payload,1,auStack_14);
            if (iVar2 == 0) {
              auStack_14[0] = CONCAT31(auStack_14[0]._1_3_,tou_info_set->num_of_tiers_in_use);
              iVar2 = zmsg_append_bytes(payload,1,auStack_14);
              if (iVar2 == 0) {
                eVar1 = append_summation_to_payload
                                  (payload,tou_info_set->num_of_tiers_in_use,
                                   tou_info_set->tier_summation);
              }
              else {
                eVar1 = 0x89;
              }
            }
            else {
              eVar1 = 0x89;
            }
          }
          else {
            eVar1 = 0x89;
          }
        }
        else {
          eVar1 = 0x89;
        }
      }
      else {
        eVar1 = 0x89;
      }
    }
    else {
      eVar1 = 0x89;
    }
  }
  else {
    eVar1 = 0x89;
  }
  return eVar1;
}

