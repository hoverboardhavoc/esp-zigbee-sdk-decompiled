/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_disc_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_general_disc_cmd_handler(int param_1,int param_2)

{
  int iVar1;
  undefined2 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  int unaff_s2;
  uint uVar5;
  byte bVar6;
  byte bStack_2d;
  uint uStack_2c;
  ushort uStack_26;
  undefined2 uStack_24;
  
  uStack_24 = 0;
  if ((((param_1 == 0) || (unaff_s2 = *(int *)(param_1 + 0x24), unaff_s2 == 0)) || (param_2 == 0))
     || (*(int *)(param_2 + 0x24) == 0)) {
    uVar3 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x391,
                          "zcl_general_disc_cmd_handler",
                          "packet && packet->payload && rsp && rsp->payload");
_L0:
    uVar4 = 1;
  }
  else {
    iVar1 = af_get_ep_desc(*(undefined1 *)(param_1 + 0x15));
    if (iVar1 == 0) {
      uVar4 = 0x81;
      goto _L0;
    }
    uVar3 = (uint)*(ushort *)(param_1 + 0x16);
    if ((*(byte *)(param_1 + 0x1a) & 8) == 0) goto _L0;
    uVar4 = 2;
  }
  puVar2 = (undefined2 *)af_endpoint_get_cluster_desc(uVar3,uVar4);
  if (puVar2 == (undefined2 *)0x0) {
    uVar4 = 0xc3;
  }
  else {
    uVar3 = zmsg_get_length(unaff_s2);
    uStack_26 = 0;
    af_read_le8(unaff_s2,&uStack_26,&uStack_24);
    af_read_le8(unaff_s2,&uStack_26,(int)&uStack_24 + 1);
    if (uStack_26 == uVar3) {
      uStack_2c = uStack_2c & 0xffffff00;
      zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_2c);
      iVar1 = zcl_cluster_template_find(*puVar2,*(undefined1 *)(puVar2 + 1));
      if (iVar1 == 0) {
        uVar4 = 0x8b;
      }
      else {
        if (*(code **)(iVar1 + 0xc) != (code *)0x0) {
          uStack_2c = 0;
          uVar3 = (**(code **)(iVar1 + 0xc))(*(char *)(param_1 + 0x20) == '\x11',&uStack_2c);
          bVar6 = 0;
          uVar5 = 0;
          while (((uVar5 < uVar3 && (uStack_2c != 0)) && (bVar6 < uStack_24._1_1_))) {
            bStack_2d = *(byte *)(uStack_2c + uVar5);
            if ((byte)uStack_24 <= bStack_2d) {
              zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&bStack_2d);
              bVar6 = bVar6 + 1;
            }
            uVar5 = uVar5 + 1 & 0xffff;
          }
          bStack_2d = uVar5 == uVar3;
          zmsg_write_bytes(*(undefined4 *)(param_2 + 0x24),0,1,&bStack_2d);
          if (*(char *)(param_1 + 0x20) == '\x11') {
            uVar4 = 0x12;
          }
          else {
            uVar4 = 0x14;
          }
          zcl_packet_setup_response(param_2,param_1,uVar4);
          return;
        }
        uVar4 = 0x8b;
      }
    }
    else {
      uVar4 = 0x80;
    }
  }
_L0:
  zcl_packet_setup_default_response(param_2,param_1,uVar4);
  return;
}

