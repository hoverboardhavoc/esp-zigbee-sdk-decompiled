/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> metering.o -> parse_block_info_set_from_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
parse_block_info_set_from_payload
          (zcl_packet_payload_t *payload,uint16_t *offset,
          ezb_zcl_metering_block_info_set_t *block_info_set)

{
  uint uVar1;
  ezb_zcl_status_t eVar2;
  uint16_t uVar3;
  uint64_t *puVar4;
  int iVar5;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined2 extraout_var_05;
  undefined3 extraout_var;
  undefined2 extraout_var_06;
  uint __nmemb;
  
  iVar5 = zcl_packet_read_variable_attr_value(0x25,block_info_set);
  if ((((iVar5 == 6) &&
       (uVar3 = af_read_le32(payload,offset,&block_info_set->bill_to_date),
       CONCAT22(extraout_var_00,uVar3) == 4)) &&
      (uVar3 = af_read_le32(payload,offset,&block_info_set->bill_to_date_time_stamp),
      CONCAT22(extraout_var_01,uVar3) == 4)) &&
     (((uVar3 = af_read_le32(payload,offset,&block_info_set->projected_bill),
       CONCAT22(extraout_var_02,uVar3) == 4 &&
       (uVar3 = af_read_le32(payload,offset,&block_info_set->projected_bill_time_stamp),
       CONCAT22(extraout_var_03,uVar3) == 4)) &&
      ((uVar3 = af_read_le8(payload,offset,&block_info_set->bill_delivered_trailing_digit),
       CONCAT22(extraout_var_04,uVar3) == 1 &&
       (uVar3 = af_read_le8(payload,offset,&block_info_set->num_of_tiers_in_use),
       CONCAT22(extraout_var_05,uVar3) == 1)))))) {
    eVar2 = parse_summation_from_payload
                      (payload,offset,block_info_set->num_of_tiers_in_use,
                       &block_info_set->tier_summation);
    iVar5 = CONCAT31(extraout_var,eVar2);
    if (iVar5 != 0) goto _L0;
    uVar3 = af_read_le8(payload,offset,&block_info_set->num_of_tiers_and_block_thresholds_in_use);
    if (CONCAT22(extraout_var_06,uVar3) == 1) {
      __nmemb = (uint)block_info_set->num_of_tiers_and_block_thresholds_in_use;
      if (__nmemb == 0) {
        return '\0';
      }
      puVar4 = (uint64_t *)calloc(__nmemb,8);
      block_info_set->tier_block_summation = puVar4;
      eVar2 = 0x89;
      if (puVar4 != (uint64_t *)0x0) {
        uVar1 = 0;
        do {
          iVar5 = zcl_packet_read_variable_attr_value
                            (payload,offset,0x25,block_info_set->tier_block_summation + uVar1);
          if (iVar5 != 6) {
            return 0x80;
          }
          uVar1 = uVar1 + 1;
        } while (__nmemb != uVar1);
        eVar2 = '\0';
      }
      return eVar2;
    }
  }
  iVar5 = 0x80;
_L0:
  return (ezb_zcl_status_t)iVar5;
}

