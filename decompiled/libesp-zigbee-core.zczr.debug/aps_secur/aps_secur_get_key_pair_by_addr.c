/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_get_key_pair_by_addr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

aps_device_key_pair_t * aps_secur_get_key_pair_by_addr(ezb_extaddr_t *src_addr)

{
  aps_device_key_pair_t *paVar1;
  int iVar2;
  ezb_extaddr_t *peVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if (src_addr != (ezb_extaddr_t *)0x0) {
    iVar2 = *(int *)((int)&src_addr->field_0 + 4);
    if ((*(int *)&src_addr->field_0 != 0 || iVar2 != 0) &&
       ((*(int *)&src_addr->field_0 != -1 || (iVar2 != -1)))) {
      uVar4 = 0;
      while( true ) {
        iVar2 = core_globals_get();
        uVar5 = *(undefined4 *)(iVar2 + 0x9a4);
        iVar2 = core_globals_get();
        uVar4 = bitmap_find_next_bit(uVar5,*(undefined2 *)(iVar2 + 0x9a8),uVar4);
        iVar2 = core_globals_get();
        if (*(ushort *)(iVar2 + 0x9a8) <= uVar4) break;
        iVar2 = core_globals_get();
        paVar1 = (aps_device_key_pair_t *)(*(int *)(iVar2 + 0x9a0) + uVar4 * 0x38);
        if ((*(int *)&(paVar1->device_address).field_0 == *(int *)&src_addr->field_0) &&
           (*(int *)((int)&(paVar1->device_address).field_0 + 4) ==
            *(int *)((int)&src_addr->field_0 + 4))) {
          return paVar1;
        }
        uVar4 = uVar4 + 1 & 0xffff;
      }
      peVar3 = aps_secur_get_tc_address();
      iVar2 = *(int *)((int)&peVar3->field_0 + 4);
      if (*(int *)&peVar3->field_0 == 0 && iVar2 == 0) {
        uVar4 = 0;
      }
      else {
        if ((*(int *)&peVar3->field_0 != -1) || (iVar2 != -1)) {
          return (aps_device_key_pair_t *)0x0;
        }
        uVar4 = 0;
      }
      while( true ) {
        iVar2 = core_globals_get();
        uVar5 = *(undefined4 *)(iVar2 + 0x9a4);
        iVar2 = core_globals_get();
        uVar4 = bitmap_find_next_bit(uVar5,*(undefined2 *)(iVar2 + 0x9a8),uVar4);
        iVar2 = core_globals_get();
        if (*(ushort *)(iVar2 + 0x9a8) <= uVar4) break;
        iVar2 = core_globals_get();
        paVar1 = (aps_device_key_pair_t *)(*(int *)(iVar2 + 0x9a0) + uVar4 * 0x38);
        peVar3 = aps_secur_get_tc_address();
        if ((*(int *)&(paVar1->device_address).field_0 == *(int *)&peVar3->field_0) &&
           (*(int *)((int)&(paVar1->device_address).field_0 + 4) ==
            *(int *)((int)&peVar3->field_0 + 4))) {
          return paVar1;
        }
        uVar4 = uVar4 + 1 & 0xffff;
      }
    }
  }
  return (aps_device_key_pair_t *)0x0;
}

