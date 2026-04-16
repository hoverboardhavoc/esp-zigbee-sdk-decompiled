/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_discovery.o -> nwk_active_scan_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: parent */
/* WARNING: Unknown calling convention */

void nwk_active_scan_callback(active_scan_result_t *scan_result,void *user_ctx)

{
  uint8_t *puVar1;
  int iVar2;
  int iVar3;
  int iStack_2c;
  ezb_extpanid_t extpanid;
  nwk_potential_parent_t parent;
  
  if (scan_result == (active_scan_result_t *)0x0) {
    iVar2 = core_globals_get();
    *(undefined1 *)(iVar2 + 0xac0) = 0;
    nwk_network_discovery_confirm(0);
    return;
  }
  if (((((scan_result->beacon_type == '\0') && (0xe < scan_result->beacon_payload_length)) &&
       (puVar1 = scan_result->beacon_payload, *puVar1 == '\0')) &&
      ((puVar1[1] == '\"' &&
       ((iVar2 = core_globals_get(), *(char *)(iVar2 + 0xac8) == '\0' ||
        ((short)(scan_result->pan_descriptor).superframe_spec < 0)))))) &&
     ((iVar2 = core_globals_get(), *(char *)(iVar2 + 0xac9) == '\0' || ((char)puVar1[2] < '\0')))) {
    iVar2 = 0x1000;
    iStack_2c = *(int *)(puVar1 + 3);
    extpanid.field_0.u64._0_4_ = *(undefined4 *)(puVar1 + 7);
    iVar3 = core_globals_get();
    if (*(int *)(iVar3 + 0x9ef) != 0 || *(int *)(iVar3 + 0x9f3) != 0) goto _L0;
    while (iVar2 = nwk_address_add_panid_mapping
                             ((scan_result->pan_descriptor).coord_panid,&iStack_2c), iVar2 == 0xff)
    {
      iVar2 = nwk_disc_table_find_weakest_pan((scan_result->pan_descriptor).lqi);
      if (iVar2 == 0xff) {
        return;
      }
      nwk_disc_table_remove_pan();
      iVar2 = nwk_address_add_panid_mapping((scan_result->pan_descriptor).coord_panid,&iStack_2c);
      if (iVar2 != 0xff) break;
      __assert_func(0,0,0,0);
      iVar2 = 0xff;
_L0:
      iVar3 = core_globals_get();
      if (*(int *)(iVar3 + iVar2 + -0x611) != iStack_2c) {
        return;
      }
      if (*(int *)(iVar3 + iVar2 + -0x60d) != extpanid.field_0.u64._0_4_) {
        return;
      }
    }
    memcpy((void *)((int)&extpanid.field_0 + 4),&(scan_result->pan_descriptor).coord_addr.u,8);
    nwk_calculate_lqa_raw((scan_result->pan_descriptor).lqi,(int)(scan_result->pan_descriptor).rssi)
    ;
    nwk_disc_table_add_parent((undefined1 *)((int)&extpanid.field_0 + 4));
  }
  return;
}

