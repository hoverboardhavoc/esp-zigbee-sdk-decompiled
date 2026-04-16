/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  puVar2 = (undefined4 *)(iVar1 + 0xd44);
  puVar3 = *(undefined4 **)(iVar1 + 0xd44);
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

