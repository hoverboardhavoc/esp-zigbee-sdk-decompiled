/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  int iVar2;
  uint uVar3;
  zdp_nwk_mgmt_nwk_update_notify_field_t zStack_4c;
  uint16_t uStack_22;
  
  if ((notify != (zdp_nwk_mgmt_nwk_update_notify_field_t *)0x0) && (ctx != (zdo_packet_ctx_t *)0x0))
  {
    zdo_packet_notify_result(ctx,0);
    return '\0';
  }
  iVar2 = __assert_func("//build/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x4bf,
                        "zdo_cb_nwk_mgmt_nwk_update_notify","notify && ctx");
  uStack_22 = 0;
  zStack_4c.status = '\0';
  zStack_4c._1_3_ = 0;
  zStack_4c.scanned_channels = 0;
  zStack_4c.total_transmissions = 0;
  zStack_4c.transmissions_failure = 0;
  zStack_4c.scanned_channels_list_count = '\0';
  zStack_4c.energy_values[0] = '\0';
  zStack_4c.energy_values[1] = '\0';
  zStack_4c.energy_values[2] = '\0';
  zStack_4c.energy_values[3] = '\0';
  zStack_4c.energy_values[4] = '\0';
  zStack_4c.energy_values[5] = '\0';
  zStack_4c.energy_values[6] = '\0';
  zStack_4c.energy_values[7] = '\0';
  zStack_4c.energy_values[8] = '\0';
  zStack_4c.energy_values[9] = '\0';
  zStack_4c.energy_values[10] = '\0';
  zStack_4c.energy_values[0xb] = '\0';
  zStack_4c.energy_values[0xc] = '\0';
  zStack_4c.energy_values[0xd] = '\0';
  zStack_4c.energy_values[0xe] = '\0';
  zStack_4c.energy_values[0xf] = '\0';
  zStack_4c.energy_values[0x10] = '\0';
  zStack_4c.energy_values[0x11] = '\0';
  zStack_4c.energy_values[0x12] = '\0';
  zStack_4c.energy_values[0x13] = '\0';
  zStack_4c.energy_values[0x14] = '\0';
  zStack_4c.energy_values[0x15] = '\0';
  zStack_4c.energy_values[0x16] = '\0';
  zStack_4c.energy_values[0x17] = '\0';
  zStack_4c.energy_values[0x18] = '\0';
  zStack_4c.energy_values[0x19] = '\0';
  zStack_4c.energy_values[0x1a] = '\0';
  if (iVar2 == 0) {
    zVar1 = 0xfe;
  }
  else if (*(int *)(iVar2 + 0x14) == 0) {
    zVar1 = 0xfe;
  }
  else {
    uVar3 = zmsg_get_length();
    af_read_le8(*(zmsg_t **)(iVar2 + 0x14),&uStack_22,&zStack_4c.status);
    af_read_le32(*(zmsg_t **)(iVar2 + 0x14),&uStack_22,&zStack_4c.scanned_channels);
    af_read_le16(*(zmsg_t **)(iVar2 + 0x14),&uStack_22,&zStack_4c.total_transmissions);
    af_read_le16(*(zmsg_t **)(iVar2 + 0x14),&uStack_22,&zStack_4c.transmissions_failure);
    af_read_le8(*(zmsg_t **)(iVar2 + 0x14),&uStack_22,&zStack_4c.scanned_channels_list_count);
    af_read_bytes(*(zmsg_t **)(iVar2 + 0x14),&uStack_22,
                  (ushort)zStack_4c.scanned_channels_list_count,(uint8_t *)zStack_4c.energy_values);
    if (uVar3 < uStack_22) {
      zVar1 = 0xfe;
    }
    else {
      zVar1 = zdo_cb_nwk_mgmt_nwk_update_notify(&zStack_4c,(zdo_packet_ctx_t *)(iVar2 + 8));
    }
  }
  return zVar1;
}

