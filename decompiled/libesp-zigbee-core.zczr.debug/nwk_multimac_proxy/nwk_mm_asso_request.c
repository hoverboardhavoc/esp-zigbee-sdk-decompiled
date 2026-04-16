/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_multimac_proxy.o -> nwk_mm_asso_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void nwk_mm_asso_request(uint8_t iface_id,mac_associate_req_t *req)

{
  undefined3 in_register_00002029;
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  iVar1 = CONCAT31(in_register_00002029,iface_id);
  iVar2 = nwk_mm_is_iface_enabled();
  if (iVar2 != 0) {
    iVar2 = core_globals_get();
    pcVar3 = *(code **)(*(int *)(*(int *)(iVar2 + iVar1 * 0xc + 0xce8) + 4) + 0x1c);
    iVar2 = core_globals_get();
    iVar2 = (*pcVar3)(*(undefined4 *)(iVar2 + iVar1 * 0xc + 0xce8),req);
    if (iVar2 == 0) {
      return;
    }
    log_write(1,"nwk_multimac_proxy.c","%s on iface %d failed: %d","mlme_asso_request",iVar1,iVar2);
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_multimac_proxy.c",0xb0,"nwk_mm_asso_request",
                  &_LC6);
  }
  __assert_func("//build/esp-zigbee/src/core/nwk/nwk_multimac_proxy.c",0xb0,"nwk_mm_asso_request",
                &_LC6);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

