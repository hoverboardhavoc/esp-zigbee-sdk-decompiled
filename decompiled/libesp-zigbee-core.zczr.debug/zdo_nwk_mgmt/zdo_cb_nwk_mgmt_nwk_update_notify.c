/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_cb_nwk_mgmt_nwk_update_notify
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t
zdo_cb_nwk_mgmt_nwk_update_notify
          (zdp_nwk_mgmt_nwk_update_notify_field_t *notify,zdo_packet_ctx_t *ctx)

{
  zdp_status_t zVar1;
  byte bVar2;
  int iVar3;
  undefined3 extraout_var;
  uint uVar4;
  zdp_nwk_mgmt_nwk_update_notify_field_t zStack_48;
  
  if ((notify != (zdp_nwk_mgmt_nwk_update_notify_field_t *)0x0) && (ctx != (zdo_packet_ctx_t *)0x0))
  {
    zdo_packet_notify_result(ctx,0);
    return '\0';
  }
  iVar3 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x4ed,
                        "zdo_cb_nwk_mgmt_nwk_update_notify","notify && ctx");
  zStack_48.status = '\0';
  zStack_48._1_3_ = 0;
  zStack_48.scanned_channels = 0;
  zStack_48.total_transmissions = 0;
  zStack_48.transmissions_failure = 0;
  zStack_48.scanned_channels_list_count = '\0';
  zStack_48.energy_values[0] = '\0';
  zStack_48.energy_values[1] = '\0';
  zStack_48.energy_values[2] = '\0';
  zStack_48.energy_values[3] = '\0';
  zStack_48.energy_values[4] = '\0';
  zStack_48.energy_values[5] = '\0';
  zStack_48.energy_values[6] = '\0';
  zStack_48.energy_values[7] = '\0';
  zStack_48.energy_values[8] = '\0';
  zStack_48.energy_values[9] = '\0';
  zStack_48.energy_values[10] = '\0';
  zStack_48.energy_values[0xb] = '\0';
  zStack_48.energy_values[0xc] = '\0';
  zStack_48.energy_values[0xd] = '\0';
  zStack_48.energy_values[0xe] = '\0';
  zStack_48.energy_values[0xf] = '\0';
  zStack_48.energy_values[0x10] = '\0';
  zStack_48.energy_values[0x11] = '\0';
  zStack_48.energy_values[0x12] = '\0';
  zStack_48.energy_values[0x13] = '\0';
  zStack_48.energy_values[0x14] = '\0';
  zStack_48.energy_values[0x15] = '\0';
  zStack_48.energy_values[0x16] = '\0';
  zStack_48.energy_values[0x17] = '\0';
  zStack_48.energy_values[0x18] = '\0';
  zStack_48.energy_values[0x19] = '\0';
  zStack_48.energy_values[0x1a] = '\0';
  if (iVar3 == 0) {
    uVar4 = 0xfe;
  }
  else if (*(zdo_packet_payload_t **)(iVar3 + 0x14) == (zdo_packet_payload_t *)0x0) {
    uVar4 = 0xfe;
  }
  else {
    zVar1 = zdo_op_nwk_mgmt_nwk_update_notify
                      (*(zdo_packet_payload_t **)(iVar3 + 0x14),&zStack_48,false);
    uVar4 = CONCAT31(extraout_var,zVar1);
    if (uVar4 == 0) {
      bVar2 = zdo_cb_nwk_mgmt_nwk_update_notify(&zStack_48,(zdo_packet_ctx_t *)(iVar3 + 8));
      uVar4 = (uint)bVar2;
    }
  }
  return (zdp_status_t)uVar4;
}

