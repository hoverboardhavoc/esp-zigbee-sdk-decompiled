/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> level_srv_cvc_ctx_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int level_srv_cvc_ctx_init(void)

{
  int iVar1;
  void *__s;
  int iVar2;
  int extraout_a1;
  undefined4 uVar3;
  undefined2 uStack_4a;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  iVar1 = level_srv_get_attr_desc(0xeff0);
  if (iVar1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/level.c",0x6b,
                  "level_srv_cvc_ctx_init","cvc_ctx_desc");
  }
  else {
    __s = calloc(1,0x40);
    *(void **)(iVar1 + 8) = __s;
    if (__s != (void *)0x0) {
      memset(__s,0,0x40);
      return 0;
    }
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/level.c",0x6d,
                        "level_srv_cvc_ctx_init","cvc_ctx_desc->data_p");
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  if (extraout_a1 == 0) {
    iVar1 = 2;
  }
  else {
    iVar2 = zcl_packet_init(&uStack_48,0);
    if (iVar2 == 0) {
      uVar3 = 0;
      if (iVar1 != 0) {
        uVar3 = 4;
      }
      iVar1 = zcl_cmd_to_packet(&uStack_48,0,0,*(undefined1 *)(extraout_a1 + 0xc),0,uVar3,8);
      if (iVar1 == 0) {
        uStack_4a = CONCAT11(uStack_4a._1_1_,*(undefined1 *)(extraout_a1 + 0x18));
        iVar1 = zmsg_append_bytes(uStack_24,1,&uStack_4a);
        if (iVar1 == 0) {
          uStack_4a = *(undefined2 *)(extraout_a1 + 0x1a);
          iVar1 = zmsg_append_bytes(uStack_24,2,&uStack_4a);
          if (iVar1 == 0) {
            uStack_4a = CONCAT11(uStack_4a._1_1_,*(undefined1 *)(extraout_a1 + 0x1c));
            iVar1 = zmsg_append_bytes(uStack_24,1,&uStack_4a);
            if (iVar1 == 0) {
              uStack_4a = CONCAT11(uStack_4a._1_1_,*(undefined1 *)(extraout_a1 + 0x1d));
              iVar1 = zmsg_append_bytes(uStack_24,1,&uStack_4a);
              if (iVar1 == 0) {
                zcl_packet_send(&uStack_48,extraout_a1 + 0x10);
                iVar1 = zcl_status_to_err();
                if (iVar1 == 0) {
                  return 0;
                }
              }
            }
          }
        }
      }
    }
    else {
      iVar1 = -1;
    }
  }
  zcl_packet_free(&uStack_48);
  return iVar1;
}

