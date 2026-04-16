/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> mac_pal_receive
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_pal_receive(uint8_t page,uint8_t channel)

{
  undefined3 in_register_00002029;
  int iVar1;
  undefined3 in_register_0000202d;
  undefined4 uVar2;
  
  uVar2 = CONCAT31(in_register_0000202d,channel);
  if (CONCAT31(in_register_00002029,page) != 0) {
    uVar2 = __assert_func(0,0,0,0);
  }
  iVar1 = ezb_plat_radio_receive(uVar2);
  if (iVar1 == 0) {
    set_state(MAC_PAL_STATE_RECEIVE);
  }
  else {
    log_write(2,"mac_pal.c","RadioReceive() failed, error: %d",iVar1);
  }
  return iVar1;
}

