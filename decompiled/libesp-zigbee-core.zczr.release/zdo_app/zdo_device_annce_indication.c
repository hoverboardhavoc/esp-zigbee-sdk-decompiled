/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app.o -> zdo_device_annce_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: signal */

void zdo_device_annce_indication(ezb_extaddr_t ieee_addr,uint16_t nwk_addr,uint8_t capability)

{
  undefined2 in_register_0000202a;
  undefined2 *puVar1;
  undefined3 in_register_0000202d;
  undefined2 in_a2;
  undefined1 in_a3;
  undefined4 uStack_38;
  ezb_extaddr_t ieee_addr_local;
  undefined2 uStack_24;
  undefined1 auStack_22 [2];
  zdo_app_signal_t signal;
  
  ieee_addr_local.field_0.u64._0_4_ = CONCAT31(in_register_0000202d,capability);
  uStack_38 = CONCAT22(in_register_0000202a,nwk_addr);
  memset(auStack_22,0,0x10);
  uStack_24 = 5;
  puVar1 = (undefined2 *)zdo_app_signal_get_params(&uStack_24);
  *puVar1 = in_a2;
  memcpy(puVar1 + 1,&uStack_38,8);
  *(undefined1 *)(puVar1 + 5) = in_a3;
  zdo_app_put_signal(&uStack_24);
  return;
}

