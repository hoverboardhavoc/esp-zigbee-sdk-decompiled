/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_formation.o -> nwk_formation_ed_scan_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_formation_ed_scan_callback(ed_scan_result_t *scan_result,void *user_ctx)

{
  uint8_t uVar1;
  uint8_t uVar2;
  int8_t iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_20;
  mac_scan_req_t scan_req;
  
  iVar4 = core_globals_get();
  if (scan_result == (ed_scan_result_t *)0x0) {
    if (((*(uint *)(iVar4 + 0xac8) & 0x7ffffff) == 0) && (*(byte *)(iVar4 + 0xace) != 0xff)) {
      uVar5 = (uint)*(byte *)(iVar4 + 0xace) << 0x1b;
      uVar6 = *(uint *)(iVar4 + 0xac8) & 0x7ffffff;
      *(uint *)(iVar4 + 0xac8) = uVar6 | uVar5;
      *(uint *)(iVar4 + 0xac8) = uVar5 | uVar6 | 1 << (*(byte *)(iVar4 + 0xacf) & 0x1f) & 0x7ffffffU
      ;
    }
    if ((*(uint *)(iVar4 + 0xac8) & 0x7ffffff) != 0) {
      nwk_disc_table_lite_init();
      scan_req.cb_u.active_scan_cb = (active_scan_callback)0x0;
      local_20 = (uint)CONCAT11(*(undefined1 *)(iVar4 + 0xacc),1);
      scan_req._0_4_ = *(undefined4 *)(iVar4 + 0xac8);
      scan_req.scan_channels.u32 = (uint32_t)nwk_formation_active_scan_callback;
      iVar4 = nwk_mm_scan_request(0,&local_20);
      if (iVar4 == 0) {
        return;
      }
    }
    iVar4 = core_globals_get();
    *(undefined1 *)(iVar4 + 0xac0) = 0;
    nwk_network_formation_confirm(0xc4);
  }
  else {
    if (scan_result->max_rssi < -0x3b) {
      uVar5 = (uint)scan_result->channel_page << 0x1b;
      uVar6 = *(uint *)(iVar4 + 0xac8) & 0x7ffffff;
      *(uint *)(iVar4 + 0xac8) = uVar6 | uVar5;
      *(uint *)(iVar4 + 0xac8) =
           uVar5 | uVar6 | 1 << (scan_result->channel_number & 0x1f) & 0x7ffffffU;
    }
    if (scan_result->max_rssi < *(char *)(iVar4 + 0xad0)) {
      uVar1 = scan_result->channel_page;
      uVar2 = scan_result->channel_number;
      iVar3 = scan_result->max_rssi;
      *(uint8_t *)(iVar4 + 0xacd) = scan_result->iface_id;
      *(uint8_t *)(iVar4 + 0xace) = uVar1;
      *(uint8_t *)(iVar4 + 0xacf) = uVar2;
      *(int8_t *)(iVar4 + 0xad0) = iVar3;
    }
  }
  return;
}

