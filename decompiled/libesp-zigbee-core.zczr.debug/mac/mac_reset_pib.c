/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_reset_pib
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_reset_pib(mac_device *dev)

{
  uint8_t uVar1;
  
  memset(dev,0,0x2c);
  mac_set_panid(dev,0xffff);
  mac_set_short_address(dev,0xffff);
  mac_pal_get_macaddr(dev);
  mac_pal_set_extaddr(dev);
  uVar1 = random_noncrypto_get_u32();
  (dev->pib).bsn = uVar1;
  uVar1 = random_noncrypto_get_u32();
  (dev->pib).dsn = uVar1;
  (dev->pib).coord_shortaddr = 0xffff;
  *(undefined4 *)&(dev->pib).coord_extaddr.field_0 = 0;
  *(undefined4 *)((int)&(dev->pib).coord_extaddr.field_0 + 4) = 0;
  (dev->pib).supported_channel_page.u32 = (dev->pib).supported_channel_page.u32 & 0x7ffffff;
  (dev->pib).supported_channel_page.u32 = 0x7fff800;
  (dev->pib).max_frame_total_wait_time = 0x256c;
  (dev->pib).max_frame_retries = '\x03';
  (dev->pib).rsp_wait_time = ' ';
  (dev->pib).min_be = '\x05';
  (dev->pib).max_be = '\b';
  (dev->pib).max_csma_backoffs = '\x04';
  (dev->pib).transaction_persistence_time = 500;
  (dev->pib).field_0x2a = (dev->pib).field_0x2a & 0xfe;
  return;
}

