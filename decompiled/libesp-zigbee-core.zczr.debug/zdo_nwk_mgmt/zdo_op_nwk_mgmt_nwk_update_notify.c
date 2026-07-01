/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_op_nwk_mgmt_nwk_update_notify
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
  int iVar1;
  uint uVar2;
  undefined3 in_register_00002031;
  uint32_t uStack_24;
  uint16_t offset;
  
  if ((payload == (zdo_packet_payload_t *)0x0) ||
     (notify == (zdp_nwk_mgmt_nwk_update_notify_field_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x215,
                  "zdo_op_nwk_mgmt_nwk_update_notify","payload && notify");
  }
  else if (CONCAT31(in_register_00002031,is_write) != 0) {
    uStack_24 = CONCAT31(uStack_24._1_3_,notify->status);
    iVar1 = zmsg_append_bytes(1,&uStack_24);
    if (iVar1 == 0) {
      uStack_24 = notify->scanned_channels;
      iVar1 = zmsg_append_bytes(payload,4,&uStack_24);
      if (iVar1 == 0) {
        uStack_24._0_2_ = notify->total_transmissions;
        iVar1 = zmsg_append_bytes(payload,2,&uStack_24);
        if (iVar1 == 0) {
          uStack_24 = CONCAT22(uStack_24._2_2_,notify->transmissions_failure);
          iVar1 = zmsg_append_bytes(payload,2,&uStack_24);
          if (iVar1 == 0) {
            uStack_24 = CONCAT31(uStack_24._1_3_,notify->scanned_channels_list_count);
            iVar1 = zmsg_append_bytes(payload,1,&uStack_24);
            if (iVar1 == 0) {
              iVar1 = zmsg_append_bytes(payload,notify->scanned_channels_list_count,
                                        notify->energy_values);
              if (iVar1 != 0) {
                iVar1 = 0x8a;
              }
            }
            else {
              iVar1 = 0x8a;
            }
          }
          else {
            iVar1 = 0x8a;
          }
        }
        else {
          iVar1 = 0x8a;
        }
      }
      else {
        iVar1 = 0x8a;
      }
    }
    else {
      iVar1 = 0x8a;
    }
    goto _L0;
  }
  uStack_24 = uStack_24 & 0xffff0000;
  uVar2 = zmsg_get_length();
  af_read_le8(payload,(uint16_t *)&uStack_24,&notify->status);
  af_read_le32(payload,(uint16_t *)&uStack_24,&notify->scanned_channels);
  af_read_le16(payload,(uint16_t *)&uStack_24,&notify->total_transmissions);
  af_read_le16(payload,(uint16_t *)&uStack_24,&notify->transmissions_failure);
  af_read_le8(payload,(uint16_t *)&uStack_24,&notify->scanned_channels_list_count);
  af_read_bytes(payload,(uint16_t *)&uStack_24,(ushort)notify->scanned_channels_list_count,
                (uint8_t *)notify->energy_values);
  if (uVar2 < (uStack_24 & 0xffff)) {
    iVar1 = 0xfe;
  }
  else {
    iVar1 = 0;
  }
_L0:
  return (zdp_status_t)iVar1;
}

