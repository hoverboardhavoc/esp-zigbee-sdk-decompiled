/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_multimac_proxy.o -> nwk_mm_start_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_mm_start_request(uint8_t iface_id,mac_start_req_t *req)

{
  int iVar1;
  undefined3 in_register_00002029;
  int iVar2;
  int iVar3;
  code *pcVar4;
  
  iVar2 = CONCAT31(in_register_00002029,iface_id);
  if (iVar2 == 0xff) {
    iVar1 = 2;
  }
  else {
    iVar3 = nwk_mm_iface_is_enabled();
    iVar1 = 3;
    if (iVar3 != 0) {
      iVar1 = core_globals_get();
      pcVar4 = *(code **)(*(int *)(*(int *)(iVar1 + iVar2 * 0xc + 0xc84) + 4) + 0x28);
      iVar1 = core_globals_get();
      iVar1 = (*pcVar4)(*(undefined4 *)(iVar1 + iVar2 * 0xc + 0xc84),req);
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  log_write(1,"nwk_multimac_proxy.c","%s on iface %d failed: %d","mlme_start_request",iVar2,iVar1);
  return iVar1;
}

