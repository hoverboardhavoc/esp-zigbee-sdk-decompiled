/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zdo_management.o -> zdo_mgmt_leave_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_mgmt_leave_confirm(nwk_leave_cnf_t *cnf)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  iVar1 = core_globals_get();
  puVar2 = (undefined4 *)(iVar1 + 0xce0);
  puVar3 = *(undefined4 **)(iVar1 + 0xce0);
  do {
    if (puVar3 == (undefined4 *)0x0) {
      return;
    }
    if (((*(byte *)(puVar3 + 7) & 1) != 0) && (*(short *)(puVar3 + -1) == 0x34)) {
      if ((puVar3[1] == *(int *)((int)&cnf->field_1 + 2)) &&
         (puVar3[2] == *(int *)((int)&cnf->field_1 + 6))) {
        *puVar2 = *puVar3;
        if (puVar3 == (undefined4 *)0x4) {
          return;
        }
        if ((code *)puVar3[5] != (code *)0x0) {
          (*(code *)puVar3[5])(cnf->status,puVar3[6]);
        }
        if (puVar3 == (undefined4 *)0x4) {
          return;
        }
        mm_free();
        return;
      }
    }
    puVar2 = puVar3;
    puVar3 = (undefined4 *)*puVar3;
  } while( true );
}

