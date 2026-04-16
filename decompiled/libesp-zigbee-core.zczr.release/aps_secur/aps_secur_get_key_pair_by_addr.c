/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_get_key_pair_by_addr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

aps_device_key_pair_t * aps_secur_get_key_pair_by_addr(ezb_extaddr_t *src_addr)

{
  undefined4 uVar1;
  aps_device_key_pair_t *paVar2;
  int iVar3;
  uint uVar4;
  
  if ((src_addr != (ezb_extaddr_t *)0x0) &&
     ((*(int *)((int)&src_addr->field_0 + 4) + 1U != (uint)(*(int *)&src_addr->field_0 == 0) ||
      (*(int *)&src_addr->field_0 - 1U < 0xfffffffe)))) {
    uVar4 = 0;
    while( true ) {
      iVar3 = core_globals_get();
      uVar1 = *(undefined4 *)(iVar3 + 0x9a4);
      iVar3 = core_globals_get();
      uVar4 = bitmap_find_next_bit(uVar1,*(undefined2 *)(iVar3 + 0x9a8),uVar4);
      iVar3 = core_globals_get();
      if (*(ushort *)(iVar3 + 0x9a8) <= uVar4) break;
      iVar3 = core_globals_get();
      paVar2 = (aps_device_key_pair_t *)(*(int *)(iVar3 + 0x9a0) + uVar4 * 0x38);
      if ((*(int *)&src_addr->field_0 == *(int *)&(paVar2->device_address).field_0) &&
         (*(int *)((int)&src_addr->field_0 + 4) ==
          *(int *)((int)&(paVar2->device_address).field_0 + 4))) {
        return paVar2;
      }
      uVar4 = uVar4 + 1 & 0xffff;
    }
    iVar3 = core_globals_get();
    if ((*(int *)(iVar3 + 0x9b0) + 1U == (uint)(*(int *)(iVar3 + 0x9ac) == 0)) &&
       (0xfffffffd < *(int *)(iVar3 + 0x9ac) - 1U)) {
      uVar4 = 0;
      while( true ) {
        iVar3 = core_globals_get();
        uVar1 = *(undefined4 *)(iVar3 + 0x9a4);
        iVar3 = core_globals_get();
        uVar4 = bitmap_find_next_bit(uVar1,*(undefined2 *)(iVar3 + 0x9a8),uVar4);
        iVar3 = core_globals_get();
        if (*(ushort *)(iVar3 + 0x9a8) <= uVar4) break;
        iVar3 = core_globals_get();
        paVar2 = (aps_device_key_pair_t *)(*(int *)(iVar3 + 0x9a0) + uVar4 * 0x38);
        iVar3 = core_globals_get();
        if ((*(int *)&(paVar2->device_address).field_0 == *(int *)(iVar3 + 0x9ac)) &&
           (*(int *)((int)&(paVar2->device_address).field_0 + 4) == *(int *)(iVar3 + 0x9b0))) {
          return paVar2;
        }
        uVar4 = uVar4 + 1 & 0xffff;
      }
    }
  }
  return (aps_device_key_pair_t *)0x0;
}

