/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_get_comm_param
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t bdb_get_comm_param(uint8_t id,uint8_t len,void *param)

{
  code *pcVar1;
  undefined3 in_register_00002029;
  int iVar2;
  undefined4 uVar3;
  ezb_err_t eVar4;
  undefined3 in_register_0000202d;
  int iVar5;
  char *pcVar6;
  undefined2 uStack_2c;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  code *pcStack_28;
  undefined4 uStack_24;
  void *pvStack_18;
  code *pcStack_14;
  
  iVar5 = CONCAT31(in_register_0000202d,len);
  iVar2 = CONCAT31(in_register_00002029,id);
  pcVar6 = (char *)param;
  if (iVar2 != 1) {
    if (iVar2 == 2) goto _L0;
    if (iVar2 != 0) {
      log_write(1,"bdb_comm.c","Invalid param id: 0x%02x",iVar2);
      pcVar1 = zdo_comm_permit_joining;
      uVar3 = __assert_func("//build/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",0x2ce,
                            bdb_get_comm_param::__func__,&_LC6);
      pvStack_18 = param;
      pcStack_14 = pcVar1;
      iVar2 = zdo_dev_joined();
      if (iVar2 == 0) {
        eVar4 = 3;
      }
      else {
        uStack_2c = 0xfffc;
        uStack_2a = (undefined1)uVar3;
        uStack_29 = 1;
        pcStack_28 = zdo_comm_permit_joining_req_cb;
        uStack_24 = uVar3;
        eVar4 = zdo_nwk_mgmt_permit_joining_req(&uStack_2c);
      }
      return eVar4;
    }
    if (iVar5 == 1) {
      iVar2 = core_globals_get();
      *(undefined1 *)param = *(undefined1 *)(iVar2 + 0xda4);
      return 0;
    }
    pcVar6 = bdb_get_comm_param::__func__;
    iVar5 = __assert_func("//build/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",0x2b5,
                          "len == sizeof(uint8_t)");
  }
  if (iVar5 == 1) {
    *pcVar6 = -0x4c;
    return 0;
  }
  iVar5 = __assert_func("//build/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",0x2ba,
                        bdb_get_comm_param::__func__,"len == sizeof(uint8_t)");
_L0:
  if (iVar5 == 4) {
    iVar2 = core_globals_get();
    if (*(char *)(iVar2 + 0xda2) == '\0') {
      uVar3 = nwk_get_pan_channel();
      *(undefined4 *)param = uVar3;
      return 0;
    }
  }
  else {
    __assert_func("//build/esp-zigbee/src/core/commissioning/bdb/bdb_comm.c",0x2bf,
                  bdb_get_comm_param::__func__,"len == sizeof(uint32_t)");
  }
  iVar2 = core_globals_get();
  if ((*(char *)(iVar2 + 0xda2) != '\x05') &&
     (iVar2 = core_globals_get(), *(char *)(iVar2 + 0xda2) != '\x01')) {
    iVar2 = core_globals_get();
    if ((*(byte *)(iVar2 + 0xdb2) & 1) != 0) {
      iVar2 = core_globals_get();
      *(undefined4 *)param = *(undefined4 *)(iVar2 + 0xda8);
      return 0;
    }
    iVar2 = core_globals_get();
    *(undefined4 *)param = *(undefined4 *)(iVar2 + 0xdac);
    return 0;
  }
  uVar3 = bdb_comm_touchlink_get_channel_mask();
  *(undefined4 *)param = uVar3;
  return 0;
}

