/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_management.o -> zdo_mgmt_leave_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_mgmt_leave_confirm(nwk_leave_cnf_t *cnf)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  iVar1 = core_globals_get();
  piVar3 = (int *)(iVar1 + 0xce0);
  do {
    do {
      piVar2 = piVar3;
      piVar3 = (int *)*piVar2;
      if (piVar3 == (int *)0x0) {
        return;
      }
    } while (((*(byte *)(piVar3 + 7) & 1) == 0) || (*(short *)(piVar3 + -1) != 0x34));
  } while ((piVar3[1] != *(int *)((int)&cnf->field_1 + 2)) ||
          (piVar3[2] != *(int *)((int)&cnf->field_1 + 6)));
  *piVar2 = *piVar3;
  zdo_mgmt_req_finish((zdo_mgmt_req_t *)(piVar3 + -1),cnf->status);
  return;
}

