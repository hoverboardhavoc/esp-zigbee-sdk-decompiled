/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_conflicts.o -> nwk_change_child_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_change_child_address(ezb_shortaddr_t child_addr)

{
  undefined2 in_register_0000202a;
  nwk_neighbor_t *child;
  undefined4 uVar1;
  uint uVar2;
  
  child = (nwk_neighbor_t *)
          nwk_neighbor_table_get_by_short(CONCAT22(in_register_0000202a,child_addr));
  if ((child != (nwk_neighbor_t *)0x0) && (uVar2 = *(uint *)&child->field_0xc, (uVar2 & 3) == 2)) {
    if ((-1 < (int)(uVar2 << 0x14)) && (((uVar2 & 0x3c0) != 0x140 && ((uVar2 & 0x3c0) != 0x180)))) {
      uVar2 = *(uint *)&child->field_0xc;
      *(uint *)&child->field_0xc = uVar2 & 0xfffffc3f | 0x200;
      if ((uVar2 & 0x400) == 0) {
        return;
      }
      nwk_child_address_change_request(child);
      return;
    }
    *(uint *)&child->field_0xc = *(uint *)&child->field_0xc & 0xfffffc3f | 0x1c0;
    uVar1 = nwk_neighbor_get_shortaddr();
    log_write(2,"nwk_conflicts.c","Address 0x%04hxconflicts with joining child, skip",uVar1);
  }
  return;
}

