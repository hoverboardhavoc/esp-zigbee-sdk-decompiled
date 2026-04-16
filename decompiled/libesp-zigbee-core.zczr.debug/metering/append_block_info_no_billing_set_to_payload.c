/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> append_block_info_no_billing_set_to_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
append_block_info_no_billing_set_to_payload
          (zcl_packet_payload_t *payload,
          ezb_zcl_metering_block_info_no_billing_set_t *block_info_no_billing_set)

{
  ezb_zcl_status_t eVar1;
  byte bVar2;
  int iVar3;
  undefined3 extraout_var;
  uint uVar4;
  uint8_t auStack_11 [5];
  
  iVar3 = zcl_packet_append_variable_attr_value(0x25,block_info_no_billing_set);
  if (iVar3 == 0) {
    auStack_11[0] = block_info_no_billing_set->num_of_tiers_in_use;
    iVar3 = zmsg_append_bytes(payload,1,auStack_11);
    if (iVar3 == 0) {
      eVar1 = append_summation_to_payload
                        (payload,block_info_no_billing_set->num_of_tiers_in_use,
                         block_info_no_billing_set->tier_summation);
      uVar4 = CONCAT31(extraout_var,eVar1);
      if (uVar4 == 0) {
        auStack_11[0] = block_info_no_billing_set->num_of_tiers_and_block_thresholds_in_use;
        iVar3 = zmsg_append_bytes(payload,1,auStack_11);
        if (iVar3 == 0) {
          bVar2 = append_summation_to_payload
                            (payload,block_info_no_billing_set->
                                     num_of_tiers_and_block_thresholds_in_use,
                             block_info_no_billing_set->tier_block_summation);
          uVar4 = (uint)bVar2;
        }
        else {
          uVar4 = 0x89;
        }
      }
    }
    else {
      uVar4 = 0x89;
    }
  }
  else {
    uVar4 = 0x89;
  }
  return (ezb_zcl_status_t)uVar4;
}

