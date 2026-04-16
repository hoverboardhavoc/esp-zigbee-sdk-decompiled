/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> metering.o -> append_tou_info_set_to_payload
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
  uint64_t *puVar1;
  ezb_zcl_status_t eVar2;
  int iVar3;
  ezb_err_t eVar4;
  uint64_t *puVar5;
  
  iVar3 = zcl_packet_append_variable_attr_value(0x25,tou_info_set);
  if (((((iVar3 == 0) && (eVar4 = zmsg_append_le32(payload,tou_info_set->bill_to_date), eVar4 == 0))
       && (eVar4 = zmsg_append_le32(payload,tou_info_set->bill_to_date_time_stamp), eVar4 == 0)) &&
      ((eVar4 = zmsg_append_le32(payload,tou_info_set->projected_bill), eVar4 == 0 &&
       (eVar4 = zmsg_append_le32(payload,tou_info_set->projected_bill_time_stamp), eVar4 == 0)))) &&
     ((eVar4 = zmsg_append_u8(payload,tou_info_set->bill_delivered_trailing_digit), eVar4 == 0 &&
      (eVar4 = zmsg_append_u8(payload,tou_info_set->num_of_tiers_in_use), eVar4 == 0)))) {
    puVar5 = tou_info_set->tier_summation;
    if ((tou_info_set->num_of_tiers_in_use == 0) || (eVar2 = '\x01', puVar5 != (uint64_t *)0x0)) {
      puVar1 = puVar5 + tou_info_set->num_of_tiers_in_use;
      do {
        if (puVar5 == puVar1) {
          return '\0';
        }
        iVar3 = zcl_packet_append_variable_attr_value(payload,0x25,puVar5);
        puVar5 = puVar5 + 1;
      } while (iVar3 == 0);
      eVar2 = 0x89;
    }
    return eVar2;
  }
  return 0x89;
}

