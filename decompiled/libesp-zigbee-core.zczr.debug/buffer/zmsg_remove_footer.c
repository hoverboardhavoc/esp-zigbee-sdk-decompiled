/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_remove_footer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void zmsg_remove_footer(zmsg_t *msg,uint16_t len)

{
  uint in_t2;
  ezb_err_t eVar1;
  uint uVar2;
  undefined2 in_register_0000202e;
  
  if ((uint)msg->tail < CONCAT22(in_register_0000202e,len)) {
    __assert_func("//build/esp-zigbee/src/core/common/buffer.c",400,"zmsg_remove_footer",
                  "len <= msg->tail");
  }
  else {
    msg->tail = msg->tail - len;
    eVar1 = zmsg_resize(msg,msg->length);
    if (eVar1 == 0) {
      return;
    }
  }
  uVar2 = __assert_func("//build/esp-zigbee/src/core/common/buffer.c",0x192,"zmsg_remove_footer",
                        0x105ac);
  if (in_t2 <= uVar2) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

