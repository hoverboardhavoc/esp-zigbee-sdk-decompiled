/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_formation.o -> nwk_formation_ed_scan_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: scan_req */
/* WARNING: Unknown calling convention */

void nwk_formation_ed_scan_callback(ed_scan_result_t *scan_result,void *user_ctx)

{
  char cVar1;
  int iVar2;
  nwk_disc_table_lite_ent_t *pnVar3;
  int iVar4;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  undefined1 auStack_1e [2];
  mac_scan_req_t scan_req;
  
  iVar2 = core_globals_get();
  if (scan_result == (ed_scan_result_t *)0x0) {
    if ((*(uint *)(iVar2 + 0xac8) & 0x7ffffff) == 0) {
      if (*(byte *)(iVar2 + 0xace) != 0xff) {
        *(uint *)(iVar2 + 0xac8) =
             1 << (*(byte *)(iVar2 + 0xacf) & 0x1f) & 0x7ffffffU |
             (uint)*(byte *)(iVar2 + 0xace) << 0x1b;
      }
    }
    if ((*(uint *)(iVar2 + 0xac8) & 0x7ffffff) == 0) {
      iVar2 = core_globals_get();
      *(undefined1 *)(iVar2 + 0xac0) = 0;
      nwk_network_formation_confirm(0xc4);
      return;
    }
    pnVar3 = nwk_disc_table_lite_get_slot('\0');
    pnVar3->channel_page = 0xff;
    pnVar3->channel_number = 0xff;
    pnVar3->pan_cnt = 0xff;
    pnVar3 = nwk_disc_table_lite_get_slot('\x01');
    pnVar3->channel_page = 0xff;
    pnVar3->channel_number = 0xff;
    pnVar3->pan_cnt = 0xff;
    iVar4 = core_globals_get();
    *(undefined1 *)(iVar4 + 0xba4) = 1;
    memset(auStack_1e,0,0xe);
    uStack_1f = *(undefined1 *)(iVar2 + 0xacc);
    scan_req._0_4_ = *(undefined4 *)(iVar2 + 0xac8);
    uStack_20 = 1;
    scan_req.scan_channels.u32 = (uint32_t)nwk_formation_active_scan_callback;
    nwk_mm_scan_request(0,&uStack_20);
  }
  else {
    cVar1 = scan_result->max_rssi;
    if (cVar1 < -0x3b) {
      *(uint *)(iVar2 + 0xac8) =
           1 << (scan_result->channel_number & 0x1f) & 0x7ffffffU |
           *(uint *)(iVar2 + 0xac8) & 0x7ffffff | (uint)scan_result->channel_page << 0x1b;
    }
    if (cVar1 < *(char *)(iVar2 + 0xad0)) {
      memcpy((void *)(iVar2 + 0xacd),scan_result,4);
    }
  }
  return;
}

