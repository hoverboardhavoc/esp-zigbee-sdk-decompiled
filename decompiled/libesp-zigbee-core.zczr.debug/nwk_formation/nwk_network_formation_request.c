/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_formation.o -> nwk_network_formation_request
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
  uint uVar3;
  undefined4 uVar4;
  int local_20;
  mac_scan_req_t scan_req;
  
  if (req == (nwk_network_formation_req_t *)0x0) {
    eVar2 = 2;
  }
  else {
    iVar1 = core_globals_get();
    if (*(char *)(iVar1 + 0xac0) == '\0') {
      iVar1 = nwk_is_joined();
      if ((iVar1 == 0) && (iVar1 = nwk_is_device_zczr(), iVar1 != 0)) {
        uVar3._0_1_ = req->scan_duration;
        uVar3._1_1_ = req->bo;
        uVar3._2_1_ = req->so;
        uVar3._3_1_ = req->field_0x7;
        if (((uVar3 >> 0x19 & 1) == 0) && (iVar1 = nwk_is_device_zc(), iVar1 == 0)) {
          eVar2 = 0x2c2;
        }
        else {
          iVar1 = core_globals_get();
          *(undefined1 *)(iVar1 + 0xac0) = 3;
          iVar1 = core_globals_get();
          nwk_formation_reset_tmp_ctx((form_tmp_s *)(iVar1 + 0xac8));
          iVar1 = core_globals_get();
          *(uint8_t *)(iVar1 + 0xacc) = req->scan_duration;
          iVar1 = core_globals_get();
          uVar4._0_1_ = req->scan_duration;
          uVar4._1_1_ = req->bo;
          uVar4._2_1_ = req->so;
          uVar4._3_1_ = req->field_0x7;
          *(byte *)(iVar1 + 0xad1) =
               *(byte *)(iVar1 + 0xad1) & 0xfe | (byte)((uint)uVar4 >> 0x19) & 1;
          scan_req.cb_u.active_scan_cb = (active_scan_callback)0x0;
          local_20 = (uint)req->scan_duration << 8;
          scan_req._0_4_ = req->scan_channels;
          scan_req.scan_channels.u32 = (uint32_t)nwk_formation_ed_scan_callback;
          eVar2 = nwk_mm_scan_request(0,&local_20);
        }
      }
      else {
        eVar2 = 0x2c2;
      }
    }
    else {
      eVar2 = 3;
    }
  }
  return eVar2;
}

