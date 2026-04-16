/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> secur_ic.o -> secur_ic_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t secur_ic_add(ezb_extaddr_t *addr,uint8_t ic_type,uint8_t *ic)

{
  _Bool _Var1;
  uint8_t uVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  ezb_err_t eVar3;
  undefined3 extraout_var_01;
  int iVar4;
  undefined3 in_register_0000202d;
  undefined1 local_40 [4];
  ds_ic_info_iterator_t itor;
  
  if (addr == (ezb_extaddr_t *)0x0) {
    eVar3 = 2;
  }
  else if (ic == (uint8_t *)0x0) {
    eVar3 = 2;
  }
  else if (CONCAT31(in_register_0000202d,ic_type) < 4) {
    _Var1 = ic_is_valid(ic_type,ic);
    if (CONCAT31(extraout_var,_Var1) == 0) {
      eVar3 = 2;
    }
    else {
      secur_ic_get_stored_ic(addr,(ds_ic_info_iterator_t *)local_40);
      if ((itor.data.ic[0x11] != '\0') &&
         ((uint)itor.data.device_address.field_0.u8[4] == CONCAT31(in_register_0000202d,ic_type))) {
        uVar2 = ic_size(ic_type);
        iVar4 = memcmp((void *)((int)&itor.data.device_address.field_0 + 5),ic,
                       CONCAT31(extraout_var_01,uVar2));
        if (iVar4 == 0) {
          return 0;
        }
      }
      ds_ic_info_delete((ds_ic_info_iterator_t *)local_40);
      local_40 = *(undefined1 (*) [4])&addr->field_0;
      itor.data.device_address.field_0.u64._0_4_ = *(undefined4 *)((int)&addr->field_0 + 4);
      itor.data.device_address.field_0.u8[4] = ic_type;
      uVar2 = ic_size(ic_type);
      memcpy((void *)((int)&itor.data.device_address.field_0 + 5),ic,CONCAT31(extraout_var_00,uVar2)
            );
      eVar3 = ds_internal_add_entry(7,local_40,0x1b);
    }
  }
  else {
    eVar3 = 2;
  }
  return eVar3;
}

