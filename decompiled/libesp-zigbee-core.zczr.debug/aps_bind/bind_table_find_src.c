/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> bind_table_find_src
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

aps_bind_src_t * bind_table_find_src(ezb_extaddr_t *src_addr,uint8_t src_ep,uint16_t cluster_id)

{
  int iVar1;
  aps_bind_src_t *paVar2;
  int iVar3;
  size_t sVar4;
  undefined3 in_register_0000202d;
  undefined2 in_register_00002032;
  uint uVar5;
  int iStack_28;
  ezb_extaddr_t tmp_src_addr;
  
  iVar3 = core_globals_get();
  uVar5 = 0;
  do {
    uVar5 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar3 + 0x96c),*(undefined2 *)(iVar3 + 0x970),uVar5);
    if (*(ushort *)(iVar3 + 0x970) <= uVar5) {
      return (aps_bind_src_t *)0x0;
    }
    iVar1 = *(int *)(iVar3 + 0x968);
    sVar4 = bind_src_size();
    paVar2 = (aps_bind_src_t *)(iVar1 + (sVar4 & 0xffff) * uVar5);
    if (((uint)paVar2->src_ep == CONCAT31(in_register_0000202d,src_ep)) &&
       ((uint)paVar2->cluster_id == CONCAT22(in_register_00002032,cluster_id))) {
      iVar1 = nwk_address_extended_by_ref(paVar2->addr_ref,&iStack_28);
      if (iVar1 == 0) {
        if ((*(int *)&src_addr->field_0 == iStack_28) &&
           (*(int *)((int)&src_addr->field_0 + 4) == tmp_src_addr.field_0.u64._0_4_)) {
          return paVar2;
        }
      }
      else {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0xa3,
                      "bind_table_find_src",
                      "(nwk_address_extended_by_ref(tmp_src->addr_ref, &tmp_src_addr)) == 0");
      }
    }
    uVar5 = uVar5 + 1 & 0xffff;
  } while( true );
}

