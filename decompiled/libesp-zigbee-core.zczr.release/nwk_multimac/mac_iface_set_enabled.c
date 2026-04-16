/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_multimac.o -> mac_iface_set_enabled
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_iface_set_enabled(uint8_t iface_id,_Bool enable)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined3 in_register_00002029;
  int iVar1;
  undefined3 in_register_0000202d;
  
  iVar1 = core_globals_get(CONCAT31(in_register_0000202d,enable));
  UNRECOVERED_JUMPTABLE = (code *)**(undefined4 **)(*(int *)(iVar1 + 0xce8) + 4);
  iVar1 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x0001003a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)
            (*(undefined4 *)(iVar1 + 0xce8),CONCAT31(in_register_00002029,iface_id),
             UNRECOVERED_JUMPTABLE);
  return;
}

