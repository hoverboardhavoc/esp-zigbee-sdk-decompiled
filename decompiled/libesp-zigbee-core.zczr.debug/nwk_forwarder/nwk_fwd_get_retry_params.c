/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_get_retry_params
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_get_retry_params(int param_1,undefined1 *param_2,undefined4 *param_3)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  byte bStack_16;
  char cStack_15;
  ushort uStack_14;
  ushort uStack_12;
  
  cStack_15 = '\0';
  zmsg_read_bytes(0,2,&uStack_12);
  zmsg_read_bytes(param_1,2,&uStack_14);
  if ((uStack_12 & 3) == 1) {
    uVar2 = zmsg_get_offset(param_1);
    zmsg_read_bytes(param_1,uVar2,1,&cStack_15);
  }
  if ((cStack_15 == '\b') || (cStack_15 == '\r')) {
    *param_2 = 0;
    *param_3 = 0;
  }
  else if (cStack_15 == '\x01') {
    sVar1 = zmsg_get_offset(param_1);
    zmsg_read_bytes(param_1,sVar1 + 1,1,&bStack_16);
    if ((bStack_16 & 0x18) == 0) {
      if ((*(ushort *)(param_1 + 0x16) & 8) == 0) {
        *param_2 = 3;
        *param_3 = 0xfe;
      }
      else {
        *param_2 = 2;
        uVar2 = random_add_jitter(0x7e);
        *param_3 = uVar2;
      }
    }
    else {
      *param_2 = 0;
      *param_3 = 0;
    }
  }
  else if (uStack_14 < 0xfff8) {
    *param_2 = 3;
    *param_3 = 0x32;
  }
  else {
    iVar3 = core_globals_get();
    *param_2 = *(undefined1 *)(iVar3 + 0x9d8);
    iVar3 = core_globals_get();
    uVar2 = random_add_jitter(*(undefined2 *)(iVar3 + 0x9d6),0x40);
    *param_3 = uVar2;
  }
  return;
}

