/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_commands.o -> aps_send_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_send_cmd(undefined4 param_1,int *param_2)

{
  undefined3 uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uStack_18;
  undefined2 uStack_14;
  byte abStack_11 [5];
  
  uVar2 = zmsg_get_length();
  if (uVar2 < 0x5b) {
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    uStack_20 = 0;
    uStack_1c = 0;
    uStack_18 = 0;
    local_30 = param_1;
    zmsg_read_bytes(param_1,0,1,abStack_11);
    uVar1 = (undefined3)(uStack_18 >> 8);
    bVar4 = abStack_11[0] >> 5 & 1 | (byte)uStack_18 & 0xfc | (byte)((abStack_11[0] >> 6 & 1) << 1);
    uStack_18 = CONCAT31(uVar1,bVar4);
    if ((*param_2 == -1) && (param_2[1] == -1)) {
      uStack_14 = 0xfffd;
      uStack_18 = CONCAT31(uVar1,bVar4) & 0xfffffffc;
      goto _L0;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_commands.c",0x3b,
                  "aps_send_cmd","zmsg_get_length(msg) <= 90");
  }
  iVar3 = nwk_address_short_by_extended(param_2,&uStack_14);
  if (iVar3 != 0) {
    return;
  }
_L0:
  zmsg_add_footer(param_1,&local_30,0x1c);
  if ((uStack_18 & 2) == 0) {
    aps_send_frame(uStack_14,&local_30);
  }
  else {
    aps_retrans_send_msg(uStack_14,0x5a,&local_30);
  }
  return;
}

