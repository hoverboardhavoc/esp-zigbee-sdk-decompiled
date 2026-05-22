/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_multimac_proxy.o -> nwk_mm_purge_tx_queue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_mm_purge_tx_queue(uint8_t iface_id,ezb_address_t *dst_addr)

{
  bool bVar1;
  undefined3 in_register_00002029;
  int iVar2;
  int iVar3;
  ezb_err_t eVar4;
  code *pcVar5;
  
  iVar3 = CONCAT31(in_register_00002029,iface_id);
  if (iVar3 == 0xff) {
    eVar4 = 0;
    bVar1 = false;
    while (!bVar1) {
      iVar3 = nwk_mm_iface_is_valid(0);
      if (iVar3 != 0) {
        iVar3 = core_globals_get();
        pcVar5 = *(code **)(*(int *)(*(int *)(iVar3 + 0xc84) + 4) + 8);
        iVar3 = core_globals_get();
        iVar3 = (*pcVar5)(*(undefined4 *)(iVar3 + 0xc84),dst_addr);
        if (iVar3 != 0) {
          log_write(1,"nwk_multimac_proxy.c","%s on iface %d failed: %d","purge_tx_queue",0,iVar3);
          eVar4 = iVar3;
        }
      }
      bVar1 = true;
    }
  }
  else {
    iVar2 = core_globals_get();
    pcVar5 = *(code **)(*(int *)(*(int *)(iVar2 + iVar3 * 0xc + 0xc84) + 4) + 8);
    iVar2 = core_globals_get();
    eVar4 = (*pcVar5)(*(undefined4 *)(iVar2 + iVar3 * 0xc + 0xc84),dst_addr);
  }
  return eVar4;
}

