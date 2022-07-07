/*
 * This file was generated by the Gradle 'init' task.
 *
 * This generated file contains a sample Java application project to get you started.
 * For more details take a look at the 'Building Java & JVM projects' chapter in the Gradle
 * User Manual available at https://docs.gradle.org/7.4.2/userguide/building_java_projects.html
 */

plugins {
    // Apply the application plugin to add support for building a CLI application in Java.
    application
}

repositories {
    // Use Maven Central for resolving dependencies.
    mavenCentral()
}

dependencies {
    // Use JUnit test framework.
    testImplementation("junit:junit:4.13.2")

    // This dependency is used by the application.
    implementation("com.google.guava:guava:30.1.1-jre")

    // Vert.x
    implementation("io.vertx:vertx-core:4.3.1")
    implementation("io.vertx:vertx-web:4.3.1")
    implementation("io.vertx:vertx-web-client:4.3.1")
    implementation("io.vertx:vertx-mqtt:4.3.1")

    // SL4J
    implementation("org.slf4j:slf4j-api:2.0.0-alpha7")

    // jssc
    implementation("io.github.java-native:jssc:2.9.4")

}

application {
    // Define the main class for the application.
    mainClass.set("it.unibo.esiot.smartgarden.service.App")
}
