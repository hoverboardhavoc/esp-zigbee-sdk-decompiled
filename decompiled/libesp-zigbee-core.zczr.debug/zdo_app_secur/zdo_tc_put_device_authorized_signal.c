/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_secur.o -> zdo_tc_put_device_authorized_signal
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_tc_put_device_authorized_signal
               (ezb_extaddr_t *device_addr,ezb_zdo_auth_type_t type,ezb_zdo_auth_status_t status)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined4 uStack_34;
  zdo_app_signal_t app_signal;
  
  app_signal.signal = 0;
  app_signal.parameters[0] = '\0';
  app_signal.parameters[1] = '\0';
  app_signal.parameters[2] = '\0';
  app_signal.parameters[3] = '\0';
  app_signal.parameters[4] = '\0';
  app_signal.parameters[5] = '\0';
  app_signal.parameters[6] = '\0';
  app_signal.parameters[7] = '\0';
  app_signal.parameters[8] = '\0';
  app_signal.parameters[9] = '\0';
  app_signal.parameters[10] = '\0';
  app_signal.parameters[0xb] = '\0';
  uStack_34 = 8;
  puVar5 = (undefined1 *)zdo_app_signal_get_params(&uStack_34);
  uVar2 = *(undefined4 *)&device_addr->field_0;
  puVar1 = (undefined4 *)((int)&device_addr->field_0 + 4);
  uVar3 = *(undefined2 *)puVar1;
  uVar4 = *puVar1;
  *puVar5 = (char)*(undefined2 *)&device_addr->field_0;
  puVar5[1] = (char)((uint)uVar2 >> 8);
  puVar5[2] = (char)((uint)uVar2 >> 0x10);
  puVar5[3] = (char)((uint)uVar2 >> 0x18);
  puVar5[4] = (char)uVar3;
  puVar5[5] = (char)((uint)uVar4 >> 8);
  puVar5[6] = (char)((uint)uVar4 >> 0x10);
  puVar5[7] = (char)((uint)uVar4 >> 0x18);
  *(undefined2 *)(puVar5 + 8) = 0xffff;
  nwk_address_short_by_extended(device_addr,puVar5 + 8);
  puVar5[10] = type;
  puVar5[0xb] = status;
  zdo_app_put_signal(&uStack_34);
  return;
}

