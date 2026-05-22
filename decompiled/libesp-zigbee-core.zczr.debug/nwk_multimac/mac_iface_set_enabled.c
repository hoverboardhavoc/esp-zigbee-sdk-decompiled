/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_multimac.o -> mac_iface_set_enabled
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_iface_set_enabled(uint8_t iface_id,_Bool enable)

{
  undefined3 in_register_00002029;
  int iVar1;
  undefined3 in_register_0000202d;
  code *pcVar2;
  
  iVar1 = core_globals_get();
  pcVar2 = (code *)**(undefined4 **)
                     (*(int *)(iVar1 + CONCAT31(in_register_00002029,iface_id) * 0xc + 0xc84) + 4);
  iVar1 = core_globals_get();
  (*pcVar2)(*(undefined4 *)(iVar1 + CONCAT31(in_register_00002029,iface_id) * 0xc + 0xc84),
            CONCAT31(in_register_0000202d,enable));
  return;
}

