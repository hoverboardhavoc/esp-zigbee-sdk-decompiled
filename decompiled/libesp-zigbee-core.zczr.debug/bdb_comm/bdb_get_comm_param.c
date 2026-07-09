/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_get_comm_param
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 bdb_get_comm_param(int param_1,int param_2,char *param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined2 uStack_2c;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  code *pcStack_28;
  undefined4 uStack_24;
  char *pcStack_18;
  code *pcStack_14;
  
  pcVar4 = param_3;
  if (param_1 != 1) {
    if (param_1 == 2) goto _L0;
    if (param_1 != 0) {
      log_write(1,"bdb_comm.c","Invalid param id: 0x%02x",param_1);
      pcVar1 = zdo_comm_permit_joining;
      uVar3 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c"
                            ,0x2e0,__func___0,&_LC6);
      pcStack_18 = param_3;
      pcStack_14 = pcVar1;
      iVar2 = zdo_dev_joined();
      if (iVar2 == 0) {
        uVar3 = 3;
      }
      else {
        uStack_2c = 0xfffc;
        uStack_2a = (undefined1)uVar3;
        uStack_29 = 1;
        pcStack_28 = zdo_comm_permit_joining_req_cb;
        uStack_24 = uVar3;
        uVar3 = zdo_nwk_mgmt_permit_joining_req(&uStack_2c);
      }
      return uVar3;
    }
    if (param_2 == 1) {
      iVar2 = core_globals_get();
      *param_3 = *(char *)(iVar2 + 0xd50);
      return 0;
    }
    pcVar4 = __func___0;
    param_2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c"
                            ,0x2c7,"len == sizeof(uint8_t)");
  }
  if (param_2 == 1) {
    *pcVar4 = -0x4c;
    return 0;
  }
  param_2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",
                          0x2cc,__func___0,"len == sizeof(uint8_t)");
_L0:
  if (param_2 == 4) {
    iVar2 = core_globals_get();
    if (*(char *)(iVar2 + 0xd4e) == '\0') {
      uVar3 = nwk_get_pan_channel();
      *(undefined4 *)param_3 = uVar3;
      return 0;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",0x2d1,
                  __func___0,"len == sizeof(uint32_t)");
  }
  iVar2 = core_globals_get();
  if ((*(char *)(iVar2 + 0xd4e) != '\x05') &&
     (iVar2 = core_globals_get(), *(char *)(iVar2 + 0xd4e) != '\x01')) {
    iVar2 = core_globals_get();
    if ((*(byte *)(iVar2 + 0xd5e) & 1) != 0) {
      iVar2 = core_globals_get();
      *(undefined4 *)param_3 = *(undefined4 *)(iVar2 + 0xd54);
      return 0;
    }
    iVar2 = core_globals_get();
    *(undefined4 *)param_3 = *(undefined4 *)(iVar2 + 0xd58);
    return 0;
  }
  uVar3 = bdb_comm_touchlink_get_channel_mask();
  *(undefined4 *)param_3 = uVar3;
  return 0;
}

