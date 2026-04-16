/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> secur_ic.o -> secur_ic_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t secur_ic_get(uint8_t *ic,secur_ic_type_t *ic_type)

{
  uint8_t uVar1;
  undefined3 extraout_var;
  ezb_err_t eVar2;
  undefined1 auStack_38 [4];
  ds_ic_info_iterator_t itor;
  
  if (ic == (uint8_t *)0x0) {
    eVar2 = 2;
  }
  else if (ic_type == (secur_ic_type_t *)0x0) {
    eVar2 = 2;
  }
  else {
    itor.index = 0;
    itor.is_done = false;
    itor._31_1_ = 0;
    secur_ic_get_stored_ic((ezb_extaddr_t *)&itor.index,(ds_ic_info_iterator_t *)auStack_38);
    if (itor.data.ic[0x11] == '\0') {
      *ic_type = itor.data.device_address.field_0.u8[4];
      uVar1 = ic_size(itor.data.device_address.field_0.u8[4]);
      memcpy(ic,(void *)((int)&itor.data.device_address.field_0 + 5),CONCAT31(extraout_var,uVar1));
      eVar2 = 0;
    }
    else {
      eVar2 = 5;
    }
  }
  return eVar2;
}

