/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_key_pair_find_or_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

aps_device_key_pair_t * aps_secur_key_pair_find_or_create(ezb_extaddr_t *src_addr)

{
  undefined4 *puVar1;
  ushort blk_nr;
  undefined4 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  uint16_t uVar5;
  aps_device_key_pair_t *__s;
  int iVar6;
  undefined2 extraout_var;
  int iVar7;
  bitmap_t *blk_busy;
  
  __s = aps_secur_get_key_pair_by_addr(src_addr);
  if (__s == (aps_device_key_pair_t *)0x0) {
    iVar6 = core_globals_get();
    iVar7 = *(int *)(iVar6 + 0x9a0);
    iVar6 = core_globals_get();
    blk_busy = *(bitmap_t **)(iVar6 + 0x9a4);
    iVar6 = core_globals_get();
    blk_nr = *(ushort *)(iVar6 + 0x9a8);
    uVar5 = mempool_alloc_idx(blk_busy,blk_nr);
    if ((CONCAT22(extraout_var,uVar5) < (uint)blk_nr) &&
       (__s = (aps_device_key_pair_t *)(CONCAT22(extraout_var,uVar5) * 0x38 + iVar7),
       __s != (aps_device_key_pair_t *)0x0)) {
      memset(__s,0,0x38);
      uVar2 = *(undefined4 *)&src_addr->field_0;
      puVar1 = (undefined4 *)((int)&src_addr->field_0 + 4);
      uVar3 = *(undefined2 *)puVar1;
      uVar4 = *puVar1;
      (__s->device_address).field_0.u8[0] = (uint8_t)*(undefined2 *)&src_addr->field_0;
      (__s->device_address).field_0.u8[1] = (uint8_t)((uint)uVar2 >> 8);
      (__s->device_address).field_0.u8[2] = (uint8_t)((uint)uVar2 >> 0x10);
      (__s->device_address).field_0.u8[3] = (uint8_t)((uint)uVar2 >> 0x18);
      (__s->device_address).field_0.u8[4] = (uint8_t)uVar3;
      (__s->device_address).field_0.u8[5] = (uint8_t)((uint)uVar4 >> 8);
      (__s->device_address).field_0.u8[6] = (uint8_t)((uint)uVar4 >> 0x10);
      (__s->device_address).field_0.u8[7] = (uint8_t)((uint)uVar4 >> 0x18);
    }
  }
  return __s;
}

