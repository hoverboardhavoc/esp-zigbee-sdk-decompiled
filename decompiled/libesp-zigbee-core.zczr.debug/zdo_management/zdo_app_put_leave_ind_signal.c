/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_management.o -> zdo_app_put_leave_ind_signal
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: signal */
/* WARNING: Unknown calling convention */

void zdo_app_put_leave_ind_signal(nwk_leave_ind_t *ind,ezb_zdo_leave_type_t leave_type)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  ezb_shortaddr_t *peVar5;
  undefined4 uStack_24;
  zdo_app_signal_t signal;
  
  signal.signal = 0;
  signal.parameters[0] = '\0';
  signal.parameters[1] = '\0';
  signal.parameters[2] = '\0';
  signal.parameters[3] = '\0';
  signal.parameters[4] = '\0';
  signal.parameters[5] = '\0';
  signal.parameters[6] = '\0';
  signal.parameters[7] = '\0';
  signal.parameters[8] = '\0';
  signal.parameters[9] = '\0';
  signal.parameters[10] = '\0';
  signal.parameters[0xb] = '\0';
  uStack_24 = 4;
  peVar5 = (ezb_shortaddr_t *)zdo_app_signal_get_params(&uStack_24);
  uVar2 = *(undefined4 *)&(ind->device_address).field_0;
  puVar1 = (undefined4 *)((int)&(ind->device_address).field_0 + 4);
  uVar3 = *(undefined2 *)puVar1;
  uVar4 = *puVar1;
  *(char *)(peVar5 + 1) = (char)*(undefined2 *)&(ind->device_address).field_0;
  *(char *)((int)peVar5 + 3) = (char)((uint)uVar2 >> 8);
  *(char *)(peVar5 + 2) = (char)((uint)uVar2 >> 0x10);
  *(char *)((int)peVar5 + 5) = (char)((uint)uVar2 >> 0x18);
  *(char *)(peVar5 + 3) = (char)uVar3;
  *(char *)((int)peVar5 + 7) = (char)((uint)uVar4 >> 8);
  *(char *)(peVar5 + 4) = (char)((uint)uVar4 >> 0x10);
  *(char *)((int)peVar5 + 9) = (char)((uint)uVar4 >> 0x18);
  *peVar5 = ind->short_address;
  *(ezb_zdo_leave_type_t *)(peVar5 + 5) = leave_type;
  zdo_app_put_signal(&uStack_24);
  return;
}

