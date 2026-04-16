/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> secur_ic.o -> secur_ic_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t secur_ic_add(ezb_extaddr_t *addr,uint8_t ic_type,uint8_t *ic)

{
  uint __n;
  uint8_t uVar1;
  ushort uVar2;
  undefined3 extraout_var;
  int iVar3;
  ezb_err_t eVar4;
  undefined3 in_register_0000202d;
  undefined1 local_40 [4];
  ds_ic_info_iterator_t itor;
  
  if (addr == (ezb_extaddr_t *)0x0) {
    return 2;
  }
  if ((ic != (uint8_t *)0x0) && (CONCAT31(in_register_0000202d,ic_type) < 4)) {
    uVar1 = ic_crc_offset(ic_type);
    iVar3 = CONCAT31(extraout_var,uVar1);
    uVar2 = crc16_next(0xffff,ic,iVar3);
    if (*(ushort *)(ic + iVar3) == (ushort)~uVar2) {
      secur_ic_get_stored_ic(addr,(ds_ic_info_iterator_t *)local_40);
      __n = iVar3 + 2U & 0xff;
      if (itor.data.ic[0x11] == '\0') {
        ds_internal_remove_entry(7,itor.data.ic._15_2_,local_40);
      }
      else if (((uint)itor.data.device_address.field_0.u8[4] ==
                CONCAT31(in_register_0000202d,ic_type)) &&
              (iVar3 = memcmp((void *)((int)&itor.data.device_address.field_0 + 5),ic,__n),
              iVar3 == 0)) {
        return 0;
      }
      local_40 = *(undefined1 (*) [4])&addr->field_0;
      itor.data.device_address.field_0.u64._0_4_ = *(undefined4 *)((int)&addr->field_0 + 4);
      itor.data.device_address.field_0.u8[4] = ic_type;
      memcpy((void *)((int)&itor.data.device_address.field_0 + 5),ic,__n);
      eVar4 = ds_internal_add_entry(7,local_40,0x1b);
      return eVar4;
    }
  }
  return 2;
}

