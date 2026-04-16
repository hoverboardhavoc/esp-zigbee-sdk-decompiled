/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_formation.o -> nwk_network_formation_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_network_formation_request(nwk_network_formation_req_t *req)

{
  int iVar1;
  ezb_err_t eVar2;
  undefined4 uVar3;
  int local_20;
  mac_scan_req_t scan_req;
  
  if (req != (nwk_network_formation_req_t *)0x0) {
    iVar1 = core_globals_get();
    eVar2 = 3;
    if (*(char *)(iVar1 + 0xac0) == '\0') {
      iVar1 = nwk_is_joined();
      if (((iVar1 == 0) && (iVar1 = nwk_is_device_zczr(), iVar1 != 0)) &&
         ((iVar1._0_1_ = req->scan_duration, iVar1._1_1_ = req->bo, iVar1._2_1_ = req->so,
          iVar1._3_1_ = req->field_0x7, iVar1 << 6 < 0 || (iVar1 = nwk_is_device_zc(), iVar1 != 0)))
         ) {
        iVar1 = core_globals_get();
        *(undefined1 *)(iVar1 + 0xac0) = 3;
        iVar1 = core_globals_get();
        *(undefined1 *)(iVar1 + 0xacd) = 0xff;
        *(undefined2 *)(iVar1 + 0xace) = 0xffff;
        *(undefined1 *)(iVar1 + 0xad0) = 0x7f;
        *(undefined4 *)(iVar1 + 0xac8) = 0;
        iVar1 = core_globals_get();
        *(uint8_t *)(iVar1 + 0xacc) = req->scan_duration;
        iVar1 = core_globals_get();
        uVar3._0_1_ = req->scan_duration;
        uVar3._1_1_ = req->bo;
        uVar3._2_1_ = req->so;
        uVar3._3_1_ = req->field_0x7;
        *(byte *)(iVar1 + 0xad1) = *(byte *)(iVar1 + 0xad1) & 0xfe | (byte)((uint)uVar3 >> 0x19) & 1
        ;
        local_20 = (uint)req->scan_duration << 8;
        scan_req._0_4_ = req->scan_channels;
        scan_req.cb_u.active_scan_cb = (active_scan_callback)0x0;
        scan_req.scan_channels.u32 = (uint32_t)nwk_formation_ed_scan_callback;
        nwk_mm_scan_request(0,&local_20);
        eVar2 = 0;
      }
      else {
        eVar2 = 0x2c2;
      }
    }
    return eVar2;
  }
  return 2;
}

