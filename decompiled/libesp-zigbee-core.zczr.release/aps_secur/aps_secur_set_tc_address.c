/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_set_tc_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_secur_set_tc_address(ezb_extaddr_t *tc_address)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined2 auStack_12 [2];
  nwk_addr_ref_t ref;
  
  iVar5 = core_globals_get();
  if ((*(int *)(iVar5 + 0x9ac) != *(int *)&tc_address->field_0) ||
     (*(int *)(iVar5 + 0x9b0) != *(int *)((int)&tc_address->field_0 + 4))) {
    auStack_12[0] = 0xffff;
    iVar5 = core_globals_get();
    iVar5 = nwk_address_ref_by_extended(iVar5 + 0x9ac,auStack_12);
    if (iVar5 == 0) {
      nwk_address_unlock_ref(auStack_12[0]);
    }
    nwk_address_by_extended(tc_address,1,auStack_12);
    iVar5 = core_globals_get();
    puVar1 = (undefined4 *)((int)&tc_address->field_0 + 4);
    uVar2 = *(undefined2 *)puVar1;
    uVar3 = *(undefined4 *)&tc_address->field_0;
    uVar4 = *puVar1;
    *(char *)(iVar5 + 0x9ac) = (char)*(undefined2 *)&tc_address->field_0;
    *(char *)(iVar5 + 0x9ad) = (char)((uint)uVar3 >> 8);
    *(char *)(iVar5 + 0x9af) = (char)((uint)uVar3 >> 0x18);
    *(char *)(iVar5 + 0x9b1) = (char)((uint)uVar4 >> 8);
    *(char *)(iVar5 + 0x9ae) = (char)((uint)uVar3 >> 0x10);
    *(char *)(iVar5 + 0x9b0) = (char)uVar2;
    *(char *)(iVar5 + 0x9b2) = (char)((uint)uVar4 >> 0x10);
    *(char *)(iVar5 + 0x9b3) = (char)((uint)uVar4 >> 0x18);
  }
  return;
}

