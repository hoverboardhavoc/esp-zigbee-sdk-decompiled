/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_conflicts.o -> nwk_address_conflict_resolve
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_address_conflict_resolve(ezb_shortaddr_t offending_addr)

{
  ezb_shortaddr_t new_addr;
  undefined2 in_register_0000202a;
  int iVar1;
  nwk_neighbor_t *child;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = nwk_is_device_zed();
  if (iVar1 == 0) {
    iVar1 = nwk_get_short_address();
    if (iVar1 == CONCAT22(in_register_0000202a,offending_addr)) {
      iVar1 = nwk_is_device_zc();
      if (iVar1 == 0) {
        new_addr = nwk_assign_shortaddr();
        nwk_change_network_address(new_addr);
        return;
      }
    }
    else {
      child = (nwk_neighbor_t *)
              nwk_neighbor_table_get_by_short(CONCAT22(in_register_0000202a,offending_addr));
      if (child != (nwk_neighbor_t *)0x0) {
        uVar3 = *(uint *)&child->field_0xc;
        if ((uVar3 & 3) == 2) {
          if (((int)(uVar3 << 0x14) < 0) || (((uVar3 & 0x3c0) - 0x140 & 0xffffffbf) == 0)) {
            *(uint *)&child->field_0xc = *(uint *)&child->field_0xc & 0xfffffc3f | 0x1c0;
            uVar2 = nwk_neighbor_get_shortaddr(child);
            log_write(2,"nwk_conflicts.c","Address 0x%04hxconflicts with joining child, skip",uVar2)
            ;
            return;
          }
          *(uint *)&child->field_0xc = uVar3 & 0xfffffc3f | 0x200;
          if ((uVar3 & 0x400) != 0) {
            nwk_child_address_change_request(child);
            return;
          }
        }
      }
    }
  }
  return;
}

