/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_init(void)

{
  undefined1 uVar1;
  int iVar2;
  
  random_init();
  iVar2 = core_globals_get();
  memset((void *)(iVar2 + 0x9d4),0,0xec);
  *(undefined4 *)(iVar2 + 0x9e0) = 0xffff1e00;
  *(undefined2 *)(iVar2 + 0x9e4) = 0xffff;
  nwk_set_rx_on_when_idle(1);
  nwk_mm_get_pib_attr(0,0x40,iVar2 + 0x9e6,8);
  *(undefined2 *)(iVar2 + 0xa34) = 0xffff;
  *(undefined1 *)(iVar2 + 0x9ef) = 0;
  *(undefined1 *)(iVar2 + 0x9f0) = 0;
  *(undefined1 *)(iVar2 + 0x9f1) = 0;
  *(undefined1 *)(iVar2 + 0x9f2) = 0;
  *(undefined1 *)(iVar2 + 0x9f3) = 0;
  *(undefined1 *)(iVar2 + 0x9f4) = 0;
  *(undefined1 *)(iVar2 + 0x9f5) = 0;
  *(undefined1 *)(iVar2 + 0x9f6) = 0;
  *(undefined4 *)(iVar2 + 0xa30) = 0;
  uVar1 = random_noncrypto_get_u32();
  *(undefined1 *)(iVar2 + 0x9da) = uVar1;
  uVar1 = random_noncrypto_get_u32();
  *(undefined2 *)(iVar2 + 0xa24) = 0x30f;
  *(undefined2 *)(iVar2 + 0x9d6) = 500;
  *(undefined1 *)(iVar2 + 0x9d8) = 2;
  *(undefined1 *)(iVar2 + 0x9de) = 0xc;
  *(undefined1 *)(iVar2 + 0xa29) = 8;
  *(undefined1 *)(iVar2 + 0x9d9) = uVar1;
  *(byte *)(iVar2 + 0xa2a) = *(byte *)(iVar2 + 0xa2a) & 0xf9 | 6;
  *(undefined1 *)(iVar2 + 0xa37) = 0x4b;
  *(undefined2 *)(iVar2 + 0xa3a) = 0x301;
  *(undefined4 *)(iVar2 + 0xa2c) = 3;
  *(undefined1 *)(iVar2 + 0x9db) = 0xff;
  nwk_set_keepalive_mode();
  nwk_secur_init();
  nwk_address_init(0x40);
  nwk_neighbor_table_init(0x40);
  nwk_neighbor_table_set_ed_capacity(0x14);
  nwk_route_table_init(0x40);
  nwk_route_disc_table_init(0x20);
  nwk_route_record_table_init(0x40);
  nwk_mm_enable_interface(0);
  nwk_fwd_init();
  iVar2 = nwk_is_device_zczr();
  if (iVar2 != 0) {
    nwk_link_mngr_init();
    return;
  }
  iVar2 = nwk_is_device_zed();
  if (iVar2 == 0) {
    return;
  }
  nwk_ed_dev_init();
  return;
}

