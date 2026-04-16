/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> parse_block_info_no_billing_set_from_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
parse_block_info_no_billing_set_from_payload
          (zcl_packet_payload_t *payload,uint16_t *offset,
          ezb_zcl_metering_block_info_no_billing_set_t *block_info_no_billing_set)

{
  ezb_zcl_status_t eVar1;
  byte bVar2;
  uint16_t uVar3;
  int iVar4;
  uint uVar5;
  undefined2 extraout_var_00;
  undefined3 extraout_var;
  undefined2 extraout_var_01;
  
  iVar4 = zcl_packet_read_variable_attr_value(0x25,block_info_no_billing_set);
  if (iVar4 == 6) {
    uVar3 = af_read_le8(payload,offset,&block_info_no_billing_set->num_of_tiers_in_use);
    if (CONCAT22(extraout_var_00,uVar3) == 1) {
      eVar1 = parse_summation_from_payload
                        (payload,offset,block_info_no_billing_set->num_of_tiers_in_use,
                         &block_info_no_billing_set->tier_summation);
      uVar5 = CONCAT31(extraout_var,eVar1);
      if (uVar5 == 0) {
        uVar3 = af_read_le8(payload,offset,
                            &block_info_no_billing_set->num_of_tiers_and_block_thresholds_in_use);
        if (CONCAT22(extraout_var_01,uVar3) == 1) {
          bVar2 = parse_summation_from_payload
                            (payload,offset,
                             block_info_no_billing_set->num_of_tiers_and_block_thresholds_in_use,
                             &block_info_no_billing_set->tier_block_summation);
          uVar5 = (uint)bVar2;
        }
        else {
          uVar5 = 0x80;
        }
      }
    }
    else {
      uVar5 = 0x80;
    }
  }
  else {
    uVar5 = 0x80;
  }
  return (ezb_zcl_status_t)uVar5;
}

