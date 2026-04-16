/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_multimac_proxy.o -> nwk_mm_poll_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_mm_poll_request(uint8_t iface_id,mac_poll_req_t *req)

{
  undefined3 in_register_00002029;
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  iVar1 = nwk_mm_is_iface_enabled();
  if (iVar1 != 0) {
    iVar2 = CONCAT31(in_register_00002029,iface_id) * 0xc;
    iVar1 = core_globals_get();
    pcVar3 = *(code **)(*(int *)(*(int *)(iVar1 + iVar2 + 0xce8) + 4) + 0x18);
    iVar1 = core_globals_get();
    iVar1 = (*pcVar3)(*(undefined4 *)(iVar1 + iVar2 + 0xce8),req);
    if (iVar1 == 0) {
      return;
    }
    log_write(1,"nwk_multimac_proxy.c","%s on iface %d failed: %d","mlme_poll_request",
              CONCAT31(in_register_00002029,iface_id),iVar1);
    iVar1 = 0;
  }
  do {
    iVar1 = __assert_func(iVar1,0,0,0);
  } while( true );
}

