/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zdo_nwk_mgmt.o -> zdo_op_nwk_mgmt_nwk_update_notify
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t
zdo_op_nwk_mgmt_nwk_update_notify
          (zdo_packet_payload_t *payload,zdp_nwk_mgmt_nwk_update_notify_field_t *notify,
          _Bool is_write)

{
  uint16_t uVar1;
  zdp_nwk_mgmt_nwk_update_notify_field_t *unaff_s0;
  zdp_status_t zVar2;
  ezb_err_t eVar3;
  uint uVar4;
  zdp_nwk_mgmt_nwk_update_notify_field_t *extraout_a1;
  undefined3 in_register_00002031;
  int iVar5;
  short sVar6;
  undefined4 uStack_24;
  uint16_t offset;
  
  iVar5 = CONCAT31(in_register_00002031,is_write);
  if ((payload == (zdo_packet_payload_t *)0x0) ||
     (unaff_s0 = notify, notify == (zdp_nwk_mgmt_nwk_update_notify_field_t *)0x0)) {
    iVar5 = 0;
    payload = (zdo_packet_payload_t *)__assert_func(0,0,0);
    notify = extraout_a1;
  }
  if (iVar5 == 0) {
    uStack_24 = (uint)uStack_24._2_2_ << 0x10;
    uVar4 = zmsg_get_length();
    af_read_le8(payload,(uint16_t *)&uStack_24,&unaff_s0->status);
    uVar1 = (uint16_t)uStack_24;
    iVar5 = zmsg_read_bytes(payload,uStack_24 & 0xffff,4,&unaff_s0->scanned_channels);
    if (iVar5 == 0) {
      sVar6 = -1;
    }
    else {
      sVar6 = uVar1 + (short)iVar5;
    }
    uStack_24 = CONCAT22(uStack_24._2_2_,sVar6);
    af_read_le16(payload,(uint16_t *)&uStack_24,&unaff_s0->total_transmissions);
    af_read_le16(payload,(uint16_t *)&uStack_24,&unaff_s0->transmissions_failure);
    af_read_le8(payload,(uint16_t *)&uStack_24,&unaff_s0->scanned_channels_list_count);
    af_read_bytes(payload,(uint16_t *)&uStack_24,(ushort)unaff_s0->scanned_channels_list_count,
                  (uint8_t *)unaff_s0->energy_values);
    if (uVar4 < (uStack_24 & 0xffff)) {
      return 0xfe;
    }
_L0:
    zVar2 = '\0';
  }
  else {
    eVar3 = zmsg_append_u8(payload,notify->status);
    if (eVar3 == 0) {
      uStack_24 = unaff_s0->scanned_channels;
      iVar5 = zmsg_append_bytes(payload,4,&uStack_24);
      if (iVar5 == 0) {
        uStack_24._0_2_ = unaff_s0->total_transmissions;
        iVar5 = zmsg_append_bytes(payload,2,&uStack_24);
        if (iVar5 == 0) {
          uStack_24 = CONCAT22(uStack_24._2_2_,unaff_s0->transmissions_failure);
          iVar5 = zmsg_append_bytes(payload,2,&uStack_24);
          if (((iVar5 == 0) &&
              (eVar3 = zmsg_append_u8(payload,unaff_s0->scanned_channels_list_count), eVar3 == 0))
             && (iVar5 = zmsg_append_bytes(payload,unaff_s0->scanned_channels_list_count,
                                           unaff_s0->energy_values), iVar5 == 0)) goto _L0;
        }
      }
    }
    zVar2 = 0x8a;
  }
  return zVar2;
}

