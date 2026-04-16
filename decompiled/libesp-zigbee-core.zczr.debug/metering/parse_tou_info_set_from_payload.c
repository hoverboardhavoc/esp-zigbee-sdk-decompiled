/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> parse_tou_info_set_from_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
parse_tou_info_set_from_payload
          (zcl_packet_payload_t *payload,uint16_t *offset,
          ezb_zcl_metering_tou_info_set_t *tou_info_set)

{
  ezb_zcl_status_t eVar1;
  uint16_t uVar2;
  int iVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  
  iVar3 = zcl_packet_read_variable_attr_value(0x25,tou_info_set);
  if (iVar3 == 6) {
    uVar2 = af_read_le32(payload,offset,&tou_info_set->bill_to_date);
    if (CONCAT22(extraout_var,uVar2) == 4) {
      uVar2 = af_read_le32(payload,offset,&tou_info_set->bill_to_date_time_stamp);
      if (CONCAT22(extraout_var_00,uVar2) == 4) {
        uVar2 = af_read_le32(payload,offset,&tou_info_set->projected_bill);
        if (CONCAT22(extraout_var_01,uVar2) == 4) {
          uVar2 = af_read_le32(payload,offset,&tou_info_set->projected_bill_time_stamp);
          if (CONCAT22(extraout_var_02,uVar2) == 4) {
            uVar2 = af_read_le8(payload,offset,&tou_info_set->bill_delivered_trailing_digit);
            if (CONCAT22(extraout_var_03,uVar2) == 1) {
              uVar2 = af_read_le8(payload,offset,&tou_info_set->num_of_tiers_in_use);
              if (CONCAT22(extraout_var_04,uVar2) == 1) {
                eVar1 = parse_summation_from_payload
                                  (payload,offset,tou_info_set->num_of_tiers_in_use,
                                   &tou_info_set->tier_summation);
              }
              else {
                eVar1 = 0x80;
              }
            }
            else {
              eVar1 = 0x80;
            }
          }
          else {
            eVar1 = 0x80;
          }
        }
        else {
          eVar1 = 0x80;
        }
      }
      else {
        eVar1 = 0x80;
      }
    }
    else {
      eVar1 = 0x80;
    }
  }
  else {
    eVar1 = 0x80;
  }
  return eVar1;
}

