/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_set_tc_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_secur_set_tc_address(ezb_extaddr_t *tc_address)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  ezb_extaddr_t *peVar5;
  int iVar6;
  undefined2 auStack_12 [2];
  nwk_addr_ref_t ref;
  
  peVar5 = aps_secur_get_tc_address();
  if ((*(int *)&peVar5->field_0 != *(int *)&tc_address->field_0) ||
     (*(int *)((int)&peVar5->field_0 + 4) != *(int *)((int)&tc_address->field_0 + 4))) {
    auStack_12[0] = 0xffff;
    aps_secur_get_tc_address();
    iVar6 = nwk_address_ref_by_extended(auStack_12);
    if (iVar6 == 0) {
      nwk_address_unlock_ref(auStack_12[0]);
    }
    nwk_address_by_extended(tc_address,1,auStack_12);
    iVar6 = core_globals_get();
    uVar2 = *(undefined4 *)&tc_address->field_0;
    puVar1 = (undefined4 *)((int)&tc_address->field_0 + 4);
    uVar3 = *(undefined2 *)puVar1;
    uVar4 = *puVar1;
    *(char *)(iVar6 + 0x9ac) = (char)*(undefined2 *)&tc_address->field_0;
    *(char *)(iVar6 + 0x9ad) = (char)((uint)uVar2 >> 8);
    *(char *)(iVar6 + 0x9ae) = (char)((uint)uVar2 >> 0x10);
    *(char *)(iVar6 + 0x9af) = (char)((uint)uVar2 >> 0x18);
    *(char *)(iVar6 + 0x9b0) = (char)uVar3;
    *(char *)(iVar6 + 0x9b1) = (char)((uint)uVar4 >> 8);
    *(char *)(iVar6 + 0x9b2) = (char)((uint)uVar4 >> 0x10);
    *(char *)(iVar6 + 0x9b3) = (char)((uint)uVar4 >> 0x18);
  }
  return;
}

