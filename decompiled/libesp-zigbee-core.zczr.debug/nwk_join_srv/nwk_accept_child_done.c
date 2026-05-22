/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_srv.o -> nwk_accept_child_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: join_ind */
/* WARNING: Unknown calling convention */

void nwk_accept_child_done
               (ezb_err_t error,ezb_extaddr_t *joiner_extaddr,nwk_join_method_t join_method)

{
  undefined2 uVar1;
  int iVar2;
  undefined3 in_register_00002031;
  uint uVar3;
  undefined4 local_20;
  nwk_join_ind_t join_ind;
  
  uVar3 = CONCAT31(in_register_00002031,join_method);
  iVar2 = nwk_neighbor_table_get_by_extended(joiner_extaddr);
  if (iVar2 == 0) {
    return;
  }
  if (-1 < *(int *)(iVar2 + 0xc) << 0x14) {
    return;
  }
  if (error != 0) {
    nwk_neighbor_table_delete();
    return;
  }
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xfffff7ff;
  if (uVar3 < 5) {
    if ((uVar3 < 3) && (1 < uVar3)) {
      if (uVar3 != 2) goto _L0;
_L0:
      nwk_neighbor_set_auth(iVar2);
      goto _L0;
    }
  }
  else {
    if (uVar3 == 5) goto _L0;
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_srv.c",0xdb,
                  "nwk_accept_child_done",&_L0);
  }
  nwk_neighbor_set_unauth(iVar2,10);
_L0:
  join_ind.iface_id = '\0';
  join_ind.join_method = '\0';
  join_ind.network_address = 0;
  join_ind.extended_address.field_0.u64._0_4_ = 0;
  join_ind.extended_address.field_0.u64._4_4_ = 0;
  local_20._0_2_ = CONCAT11(join_method,(char)(*(uint *)(iVar2 + 0xc) >> 0xd)) & 0xff1f;
  local_20 = (uint)(ushort)local_20;
  uVar1 = nwk_neighbor_get_shortaddr(iVar2);
  local_20 = CONCAT22(uVar1,(ushort)local_20);
  nwk_neighbor_get_extaddr(iVar2,&join_ind);
  nwk_join_indication(&local_20);
  return;
}

