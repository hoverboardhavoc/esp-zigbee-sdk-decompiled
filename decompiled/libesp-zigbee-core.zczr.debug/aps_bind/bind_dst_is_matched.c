/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> bind_dst_is_matched
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool bind_dst_is_matched(aps_bind_dst_t *dst,ezb_address_t *dst_addr,uint8_t dst_ep)

{
  ezb_addr_mode_t eVar1;
  int iVar2;
  undefined3 in_register_00002031;
  char *pcVar3;
  char *pcVar4;
  ezb_grpaddr_t eStack_18;
  ezb_extaddr_t tmp_dst_addr;
  
  eVar1 = dst_addr->addr_mode;
  if ((ushort)(eVar1 == '\x01') != (*(ushort *)&dst->ref_cnt >> 8 & 1)) {
    return false;
  }
  if (eVar1 == '\x01') {
    if ((dst->field_0).extaddr.addr_ref == (dst_addr->u).short_addr) {
      return true;
    }
    return false;
  }
  if (eVar1 != '\x03') {
    __assert_func("//build/esp-zigbee/src/core/aps/aps_bind.c",0xc6,"bind_dst_is_matched",&_LC3);
    return false;
  }
  if ((CONCAT31(in_register_00002031,dst_ep) != 0xff) &&
     ((uint)(dst->field_0).extaddr.endpoint != CONCAT31(in_register_00002031,dst_ep))) {
    return false;
  }
  iVar2 = nwk_address_extended_by_ref((dst->field_0).extaddr.addr_ref,&eStack_18);
  if (iVar2 == 0) {
    pcVar4 = *(char **)((int)&dst_addr->u + 4);
    if ((dst_addr->u).group_addr != eStack_18) {
      return false;
    }
  }
  else {
    pcVar4 = "(nwk_address_extended_by_ref(dst->extaddr.addr_ref, &tmp_dst_addr)) == 0";
    pcVar3 = "bind_dst_is_matched";
    __assert_func("//build/esp-zigbee/src/core/aps/aps_bind.c",0xbe);
    tmp_dst_addr.field_0.u64._0_4_ = pcVar3;
  }
  if (pcVar4 != (char *)tmp_dst_addr.field_0.u64._0_4_) {
    return false;
  }
  return true;
}

